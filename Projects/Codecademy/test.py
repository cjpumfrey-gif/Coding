A = [1, 2, 2, 1]
B = set([1, 2, 2, 1])

SA = sum(A)
BA = sum(B)

if SA > BA:
    print("A is more than B")
elif BA > SA:
    print("B is more than A")
else:
    print("They are Equal")
