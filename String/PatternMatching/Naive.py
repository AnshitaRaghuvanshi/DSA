#To count the substrings present in string using Naive Pattern Matching
# TC  O(m*(n-m+1))
def count_substring(string, sub_string):
    n=len(string)
    m=len(sub_string)
    i=0
    count=0
    for i  in range(i,n-m+1):
        j=0
        while(j<m):
            if string[i+j]!=sub_string[j]:
                break
            j+=1
            if j==m:
                count+=1
    return count
if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()
    
    count = count_substring(string, sub_string)
    print(count)
