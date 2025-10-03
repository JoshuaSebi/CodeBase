def average(dict1):
    tot=sum(dict1.values())
    c=len(dict1)
    avg=tot/c
    return avg



student_grades = {
"Maths" : 100,
"Science" : 98,
"History" : 100,
"Geography" : 100,
"English" : 98
}

print(f"Average marks: {average(student_grades)}")
