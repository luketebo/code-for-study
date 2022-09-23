import os
import shutil

file = "Fddd.txt"
print(os.getcwd())
current_folder = os.listdir("./TXT")

for x in current_folder:
    file_dir = "./TXT" + "/" + x
    shutil.copy(file, current_folder)