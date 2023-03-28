import nltk
from nltk.corpus import webtext

for fileid in webtext.fileids():
    print(fileid)
    words = webtext.words(fileid)
    print(f"文件长度: {len(words)}\n")
    print(f"单词数量: {len(set(words))}\n")
    print(f"词汇表长度: {len(set(words))}\n")