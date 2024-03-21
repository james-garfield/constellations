import os
import urllib.parse


files = ["assets/images/v1/" + x for x in os.listdir("assets/images/v1")]

change = [
    "ñ"
]

new_name = None
parsed = ""

for file in files:
    new_name = None
    parsed = urllib.parse.unquote(file)
    for letter in change:
        if not letter in parsed:
            continue
        new_name = parsed.replace(letter, "n")
    if new_name:
        os.replace(file, new_name)