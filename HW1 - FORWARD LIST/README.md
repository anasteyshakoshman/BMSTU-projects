List1(1, 199)
list 1 : 199

After push_back(1)
list 1 : 199 1

After push_front(87)
list 1 : 87 199 1

After resize(5, 23)
list 1 : 87 199 1 23 23

After pop_back()
list 1 : 87 199 1 23

List2(list1)
list 2 : 87 199 1 23

After pop_front()
list 2 : 199 1 23

After remove(199)
list 1 : 87 1 23

After push_back(i), i = 0, 1, 2
list 2 : 0 1 2

After swap
list 1 : 0 1 2
list 2 : 87 1 23

After assign(5, 16)
list 1 : 0 1 2 16 16 16 16 16

list 3 : 95.4 92.8 88.2 81.6 73 62.4 49.8 35.2 18.6 0 4.9 4.9

After sort()
list 3 : 0 4.9 4.9 18.6 35.2 49.8 62.4 73 81.6 88.2 92.8 95.4

list 2 : 87 1 23 5 5 5 5 5 45 45 45 45 45 45 45 45 45 45 87

After unique()
list 2 : 87 1 23 5 45

After reverse()
list 2 : 45 5 23 1 87

After insert_after(list2.begin(), 8)
list 2 : 45 8 5 23 1 87

After erase_after(list2.begin())
list 2 : 45 5 23 1 87

After insert_after(it, 653), it = Head->Next->Next
list 2 : 45 5 23 653 1 87

After erase_after(it, list2.end())
list 2 : 45 5 23 1 87
Для продолжения нажмите любую клавишу . . .
