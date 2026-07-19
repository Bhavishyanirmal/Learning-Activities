import java.util.Scanner;

public class cnpro {

    // Find IP Class
    public static String getClass(String ip) {
        int firstOctet = Integer.parseInt(ip.split("\\.")[0]);

        if (firstOctet >= 1 && firstOctet <= 126) return "Class A";
        if (firstOctet >= 128 && firstOctet <= 191) return "Class B";
        if (firstOctet >= 192 && firstOctet <= 223) return "Class C";
        if (firstOctet >= 224 && firstOctet <= 239) return "Class D (Multicast)";
        if (firstOctet >= 240 && firstOctet <= 255) return "Class E (Experimental)";

        return "Invalid Class";
    }

    // Convert CIDR to Subnet Mask
    public static String cidrToSubnetMask(int cidr) {
        int mask = 0xFFFFFFFF << (32 - cidr);
        return ((mask >> 24) & 0xFF) + "." + ((mask >> 16) & 0xFF) + "." +
               ((mask >> 8) & 0xFF) + "." + (mask & 0xFF);
    }

    // Get Network ID
    public static String getNetworkID(String ip, String subnetMask) {
        String[] ipParts = ip.split("\\.");
        String[] maskParts = subnetMask.split("\\.");
        int[] networkID = new int[4];

        for (int i = 0; i < 4; i++) {
            networkID[i] = Integer.parseInt(ipParts[i]) & Integer.parseInt(maskParts[i]);
        }

        return networkID[0] + "." + networkID[1] + "." + networkID[2] + "." + networkID[3];
    }

    // Get Broadcast Address
    public static String getBroadcastAddress(String networkID, String subnetMask) {
        String[] netParts = networkID.split("\\.");
        String[] maskParts = subnetMask.split("\\.");
        int[] broadcast = new int[4];

        for (int i = 0; i < 4; i++) {
            broadcast[i] = (Integer.parseInt(netParts[i]) & Integer.parseInt(maskParts[i])) | (~Integer.parseInt(maskParts[i]) & 255);
        }

        return broadcast[0] + "." + broadcast[1] + "." + broadcast[2] + "." + broadcast[3];
    }

    // Convert IPv4 to IPv6
    public static String convertIPv4ToIPv6(String ipv4) {
        String[] parts = ipv4.split("\\.");
        return "0000:0000:0000:0000:0000:FFFF:" +
                String.format("%02X%02X:%02X%02X",
                        Integer.parseInt(parts[0]), Integer.parseInt(parts[1]),
                        Integer.parseInt(parts[2]), Integer.parseInt(parts[3]));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // User input for IP Address
        System.out.print("Enter IP Address: ");
        String ipAddress = scanner.nextLine();

        // User input for CIDR
        System.out.print("Enter CIDR (e.g., 24 for /24): ");
        int originalCidr = scanner.nextInt();

        // User input for number of required subnets
        System.out.print("Enter the number of subnets: ");
        int requiredSubnets = scanner.nextInt();

        // Calculate new CIDR based on required subnets
        int newCidr = originalCidr + (int) (Math.log(requiredSubnets) / Math.log(2));

        // Get Subnet Mask
        String subnetMask = cidrToSubnetMask(newCidr);

        // Get Network ID
        String networkID = getNetworkID(ipAddress, subnetMask);

        // Get Broadcast Address
        String broadcastAddress = getBroadcastAddress(networkID, subnetMask);

        // Get Class of IP
        String ipClass = getClass(ipAddress);

        // Calculate Number of Addresses per Subnet
        int numAddressesPerSubnet = (int) Math.pow(2, (32 - newCidr));

        // Display Results
        System.out.println("\nResults:");
        System.out.println("IP Address: " + ipAddress);
        System.out.println("Class: " + ipClass);
        System.out.println("Network ID: " + networkID);
        System.out.println("Subnet Mask: " + subnetMask);
        System.out.println("Number of Addresses in Each Subnet: " + numAddressesPerSubnet);
        System.out.println("Broadcast Address: " + broadcastAddress);
        System.out.println("IPv4 to IPv6: " + convertIPv4ToIPv6(ipAddress));

        // Calculate Subnet ID Ranges
        System.out.println("\nSubnet ID Ranges:");
        String[] netParts = networkID.split("\\.");
        int base = Integer.parseInt(netParts[3]);
        for (int i = 0; i < requiredSubnets; i++) {
            int start = base + (i * numAddressesPerSubnet);
            int end = start + numAddressesPerSubnet - 1;
            System.out.println("Subnet " + i + ": " +
                    netParts[0] + "." + netParts[1] + "." + netParts[2] + "." + start + " to " +
                    netParts[0] + "." + netParts[1] + "." + netParts[2] + "." + end);
        }

        scanner.close();
    }
}
