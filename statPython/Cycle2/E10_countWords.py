def countCheck(str1):
    words=len(str1.split())
    print ("Words = ",words)

    vow=cons=splChar=0
    for x in str1:
        if x.isalpha():
            if x in 'aeiou':
                vow+=1
            else:
                cons+=1
        else:
            if x!=' ':
                splChar+=1
    print("Vowels = ",vow)
    print("Consonants = ",cons)
    print("Special Chars = ",splChar)

para = input("Enter the string:\n")
countCheck(para)
