"""
2020 카카오 채용
프로그래머스 60057
"""

def zip_string(string, set_num):
    string_len = len(string)
    con_num = 1
    zip_string = ""
 
    for i in range(0,string_len + set_num- 1,set_num):
        if string[i:i+set_num] == string[i+set_num:i+2*set_num]:
            con_num += 1
        
        else:
            if con_num == 1:
                zip_string += string[i:i+set_num]
            
            else:
                zip_string += str(con_num) + string[i:i+set_num]
            
            con_num = 1
    
    return len(zip_string)

def solution(s):
    answer = 1001
    str_len = len(s)

    for i in range(1, str_len + 1):
        res = zip_string(s, i)
        if res < answer:
            answer = res

    return answer