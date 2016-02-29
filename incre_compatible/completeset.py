__author__ = 'xiangyuzhang'

import time

def completeset(Allow):
                # Allow is a list with allowed bits, like ['00','01']
    # print Allow
    result = []
    complete = []
    if len(Allow[0]) is 2:
        complete = ['00', '01', '10', '11']
    elif len(Allow[0]) is 3:
        complete = ['000', '001', '010', '011', '100', '101', '110', '111']
    elif len(Allow[0]) is 4:
        complete = ['0000', '0001', '0010', '0011', '0100', '0101', '0110', '0111', '1000', '1001', '1010', '1011', '1100', '1101', '1110', '1111']
    elif len(Allow[0]) is 1:
        complete = ['0','1']
    # print complete
    for i in complete:
        if i not in Allow:
            result.append(i)
    # print result
    # time.sleep(1000)
    return result


