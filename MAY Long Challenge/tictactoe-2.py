for _ in range(int(input())):
    arr=[0]*3
    arr[0]= input()
    arr[1]= input()
    arr[2]= input()
    X_=0
    O_=0
    tt=0
    row_wise=0
    O_jeeta= False
    X_jeeta = False
    X_count=0
    O_count=0
    for i in range(3):
        word= arr[i]
        for i in range(3):
            if word[i]=="X":
                X_+=1
                X_count+=1
            elif word[i]=="O":
                O_+=1
                O_count+=1
            elif word[i]=="_":
                tt+=1

        if X_count==3:
            row_wise+=1
            X_jeeta = True
        if O_count==3:
            row_wise+=1
            O_jeeta= True 
        X_count=0
        O_count=0
    row_mein_khushi= row_wise
    if O_jeeta and X_ != O_:
        print("3")
        continue
    if X_jeeta and X_ - O_ != 1:
        print(3)
        continue
    if (X_ - O_)>1 or (X_ - O_)<0:
        print("3")
        continue

    for i in range(3):
        if arr[0][i]=="X":
            X_count+=1
        if arr[0][i]=="O":
            O_count+=1
        if arr[1][i]=="X":
            X_count+=1
        if arr[1][i]=="O":
            O_count+=1
        if arr[2][i]=="X":
            X_count+=1
        if arr[2][i]=="O":
            O_count+=1
        if X_count==3 :
            row_wise+=1
            X_jeeta = True
        if O_count==3:
            row_wise+=1
            O_jeeta=True
        X_count=0
        O_count=0
    coloumn_mein_khushi= row_wise - row_mein_khushi
    if (O_jeeta and X_ != O_) or (X_jeeta and X_ - O_ != 1):
        print("3")
        continue
    
    if arr[0][0]=="X":
        X_count+=1
    if arr[0][0]=="O":
        O_count+=1
    if arr[1][1]=="X":
        X_count+=1
    if arr[1][1]=="O":
        O_count+=1
    if arr[2][2]=="X":
        X_count+=1
    if arr[2][2]=="O":
        O_count+=1
    if X_count==3:
        row_wise+=1
        X_jeeta = True
    if O_count==3:
        row_wise+=1
        O_jeeta=True
    X_count=0
    O_count=0
    if (O_jeeta and X_ != O_) or (X_jeeta and X_ - O_ != 1):
        print("3")
        continue
    
    if arr[0][2]=="X":
        X_count+=1
    if arr[0][2]=="O":
        O_count+=1
    if arr[1][1]=="X":
        X_count+=1
    if arr[1][1]=="O":
        O_count+=1
    if arr[2][0]=="X":
        X_count+=1
    if arr[2][0]=="O":
        O_count+=1
    if X_count==3 :
        row_wise+=1
        X_jeeta = True
    if O_count==3:
        row_wise+=1
        O_jeeta=True 
    X_count=0
    O_count=0
    if (O_jeeta and X_ != O_) or (X_jeeta and X_ - O_ != 1):
        print("3")
        continue
    diagnol_mein_khushi = row_wise - (row_mein_khushi + coloumn_mein_khushi)
    if row_mein_khushi>1 or coloumn_mein_khushi>1:
        print("3")
        continue
    if coloumn_mein_khushi==1 or row_mein_khushi==1:
        print("1")
        continue
    if diagnol_mein_khushi==2 or diagnol_mein_khushi==1:
        print("1")
        continue
    if row_wise==1:
        print("1")
        continue
    if __==0:
        print("1")
        continue
    else:
        print("2")
        
    
        

    
        
        






