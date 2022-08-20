import time
import json
import requests
from datetime import datetime
import pandas as pd
import numpy as np


def get_data():
    url = 'https://view.inews.qq.com/g2/getOnsInfo?name=disease_h5'
    response = requests.get(url).json()
    data = json.loads(response['data'])
    return data


data = get_data()

print(data)
