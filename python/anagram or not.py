n=input('Enter string:')
p=input('enter string2:')

a=sorted(n)
b=sorted(p)

if a==b:
    print('anagram')
else:
    print('not anagrams')
