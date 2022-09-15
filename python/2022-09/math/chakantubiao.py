import pandas as pd
import numpy as np
import xlrd
from matplotlib import pyplot

def drawBar():
    pass

workbook = xlrd.open_workbook_xls("demo.xlsx")
sheet = workbook.sheet_by_index(0)
A1 = []
B1 = []
for i in range(1, sheet.nrows):
    A1.append(sheet.cell_value(i, 0))
    B1.append(sheet.cell_value(i, 1))

if len(A1) != len(B1):
    print("False")
    