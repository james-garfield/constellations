import requests
import re
import shutil

from pathlib import Path


urls = [
    "https://constelacionesmagicas.constelacionesfloresmagicas.cl/Images/",
    "https://constelacionesmagicas.constelacionesfloresmagicas.cl/Images/v1/",
    "https://constelacionesmagicas.constelacionesfloresmagicas.cl/Images/v2/",
    "https://constelacionesmagicas.constelacionesfloresmagicas.cl/Images/v3/",
    "https://constelacionesmagicas.constelacionesfloresmagicas.cl/Images/v4/",
    "https://constelacionesmagicas.constelacionesfloresmagicas.cl/Images/v5/",
]


def download_file(url:str):
    response = requests.get(url, stream=True)
    
    # Get directory to go in
    dir_to_go_in = "assets/images"

    paths = url.split("/")
    print(paths)
    ending = paths[-2]
    if "v" in ending:
        dir_to_go_in += "/" + ending
    p = Path(dir_to_go_in)
    if not p.exists():
        p.mkdir()

    file_name = paths[-1]

    with open(dir_to_go_in + "/" + file_name, 'wb') as file:
        shutil.copyfileobj(response.raw, file)
    del response


endings = ['png', 'jpg', 'gif']
for url in urls:
    response = requests.get(url)
    pattern = re.compile(r'<a\s+[^>]*href\s*=\s*["\']?([^"\'>\s]+)')
    hrefs = pattern.findall(response.text)

    for href in hrefs:
        # Check if href is to a file
        if not href.split('.')[-1] in endings:
            continue
        
        path = url + href
        print(path)

        download_file(path)