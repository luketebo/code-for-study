class Key:
    def __init__(self, *args) -> None:
        """初始化参数
        """
        self.ciphertext = args[0]
        self.key = args[1]
        self.dir = 0
        self.count = ""
        self.finish = []

    def get_bit_val(self, byte, index):
        """得到某个字节的某一位的值

        Args:
            byte (dec): 待取值的字节值
            index (int): 代取位的序号

        Returns:
            Boolean: 返回的值
        """
        if byte & (1 << index):
            return 1
        else:
            return 0

    def dec2bin(self, dec):
        """dec => bin

        Args:
            dec (int): 十进制值

        Returns:
            bin: 返回一个二进制值
        """
        ans = ""
        temp = []
        while dec:
            quo = dec % 2
            dec = dec // 2
            temp.append(quo)
        while temp:
            ans += str(temp.pop())

        if (len(ans) < 8):
            i = 8 - len(ans)
            while i > 0:
                ans = '0' + ans
                i -= 1
        return ans

    def bin2dec(self, bin):
        """bin => dec

        Args:
            bin (bin): 二进制值

        Returns:
            int: 十进制值
        """
        ans = 0
        for i in range(len(bin)):
            ans += int(bin[i]) * 2 ** (len(bin) - i - 1)
        return ans

    def xor(self, x, y):
        """异或运算

        Args:
            x (bin): 第一个二进制值
            y (bin): 第二个二进制值

        Returns:
            bin: 返回一个完成了异或运算的二进制值
        """
        return '{0:b}'.format(int(x, 2) ^ int(y, 2))

    def encrypt(self):
        """加密算法
        """
        listDec = []
        listBin = []
        listCip = []
        index = 0
        newKey = [str(a) for a in str(self.key)]
        newKeyList = []
        for item in newKey:
            newKeyList.append(self.dec2bin(ord(item)))
        for item in self.ciphertext:
            listDec.append(ord(item))
        for item in listDec:
            listBin.append(self.dec2bin(item))
        for i in newKeyList:
            index = index + 1

        for i in range(index):
            listCip.append(self.xor(newKeyList[i], listBin[i]))

        newCip = []
        for item in listCip:
            newCip.append("0" + item)

        self.dir = self.get_bit_val(int(self.key[0]), 7)

        for i in range(1, len(self.key)):
            self.count += str(self.get_bit_val(int(self.key[i]), 0))
        count = self.bin2dec(self.count)
        allCip = ""

        for item in newCip:
            allCip += item
        endCip = ""
        # 0 <- 1 ->
        if (0 == self.dir):
            endCip = allCip[count:32] + allCip[0:count]
        else:
            endCip = allCip[32 - count:32] + allCip[:32 - count]

        # 切割
        finCip = []
        a = 0
        for i in range(4):
            finCip.append(endCip[a:a + 8])
            a = a + 8
        good = []
        for item in finCip:
            good.append(self.bin2dec(item))
        self.finish = finCip
        Liu = ""
        for item in good:
            Liu += chr(item)
        print("加密后： ", Liu)

    def decrypt(self):
        """解密算法
        """
        count = self.bin2dec(self.count)
        dir = self.dir
        endCip = ""
        for item in self.finish:
            endCip += item
        finCip = ''
        if (0 == dir):
            finCip = endCip[32 - count:32] + endCip[:32 - count]
        else:
            finCip = endCip[count:32] + endCip[:count]
        text = []
        a = 0
        for i in range(4):
            text.append(finCip[a:a + 8])
            a = a + 8
        newKey = [str(a) for a in str(self.key)]
        newKeyList = []
        for item in newKey:
            newKeyList.append(self.dec2bin(ord(item)))
        index = 0
        for i in newKeyList:
            index = index + 1

        TextCip = []
        for i in range(index):
            TextCip.append(self.bin2dec(self.xor(newKeyList[i], text[i])))

        Qu = ""
        for item in TextCip:
            Qu += chr(item)
        print("解密后： ", Qu)


if __name__ == "__main__":
    """目前有缺陷，密钥必须和密文的长度一样，不然会出错
    """
    key = Key("love", "1234")
    print("原文：   ", "love")
    key.encrypt()
    key.decrypt()
