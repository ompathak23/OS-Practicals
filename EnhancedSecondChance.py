import random
def enhanced_second_chance(reference_string, frame_num, page_num):
    pagefault = 0
    memqueue = []
    memqueue0 = []
    memqueue1 = []
    memqueue2 = []
    memqueue3 = []
    selectdict = {}
    for page in range(page_num):
        selectdict.update({page + 1: [0, random.randint(0, 1)]})
    for reference in reference_string:

        if reference in memqueue0:
            memqueue0.remove(reference)
            memqueue2.append(reference)
            selectdict[reference][0] = 1
        elif reference in memqueue1:
            memqueue1.remove(reference)
            memqueue3.append(reference)
            selectdict[reference][0] = 1
        elif reference in memqueue2 or reference in memqueue3:
            continue
        else:
            pagefault += 1
            if len(memqueue0) + len(memqueue1) + len(memqueue2) + len(memqueue3) < frame_num:
                if selectdict[reference][1] == 0:
                    memqueue0.append(reference)
                else:
                    memqueue1.append(reference)
            elif len(memqueue0) != 0:
                memqueue0.remove(memqueue0[0])
                if selectdict[reference][1] == 0:
                    memqueue0.append(reference)
                else:
                    memqueue1.append(reference)
            elif len(memqueue1) != 0:
                memqueue1.remove(memqueue1[0])
                if selectdict[reference][1] == 0:
                    memqueue0.append(reference)
                else:
                    memqueue1.append(reference)
            elif len(memqueue2) != 0:
                selectdict[memqueue2[0]][0] = 0
                memqueue2.remove(memqueue2[0])
                if selectdict[reference][1] == 0:
                    memqueue0.append(reference)
                else:
                    memqueue1.append(reference)
                for item in memqueue2:
                    selectdict[item][0] = 0
                    memqueue0.append(item)
                    memqueue2.remove(item)
                    selectdict[item][0] = 0
            elif len(memqueue3) != 0:
                selectdict[memqueue3[0]][0] = 0
                memqueue3.remove(memqueue3[0])
                if selectdict[reference][1] == 0:
                    memqueue0.append(reference)
                else:
                    memqueue1.append(reference)
                for item in memqueue3:
                    selectdict[item][0] = 0
                    memqueue1.append(item)
                    memqueue3.remove(item)
                    selectdict[item][0] = 0
        memqueue = []
        for i in memqueue0:
            memqueue.append(i)
        for i in memqueue1:
            memqueue.append(i)
        for i in memqueue2:
            memqueue.append(i)
        for i in memqueue3:
            memqueue.append(i)

    return pagefault


page_num = 10
frame_num = 5
reference_string = [2,2,3,4,5,6,6,3,5,7,8]
ans=enhanced_second_chance(reference_string,frame_num,page_num)
print("Pages ",page_num)
print("Frames ",frame_num)
print("Reference String ",reference_string)
print("Page Faults", ans)