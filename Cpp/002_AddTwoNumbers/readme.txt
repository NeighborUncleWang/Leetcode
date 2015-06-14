Time complexity: O(n)
Space complexity: O(1)
001.cpp has a headnode, so it will use an extra space to store the headnode. But the insert of the linkedlist brcomes simplier. The speed is 40ms.
002.cpp does not have headnode, the code becomes longer. The speed is 44ms.
Be careful, consider when you generate a final carry, there should be an extra digit for the sum, such as 1 + 99 = 100.
