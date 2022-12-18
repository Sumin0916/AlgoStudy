"""
프린터 큐
"""
test_case = int(input())

for i in range(test_case):
    doc_len, q_ind = map(int, input().split())
    doc_lst = list(map(int, input().split()))
    print_num = 0

    for j in enumerate(doc_lst):
        doc_lst[j[0]] = list(j)
    
    while True:
        max_impor = max(doc_lst, key=lambda x: x[1])[1]
        check_impor = doc_lst.pop(0)

        if check_impor[1] == max_impor:
            print_num += 1

            if q_ind == check_impor[0]:
                print(print_num)
                break

        else:
            doc_lst.append(check_impor)
