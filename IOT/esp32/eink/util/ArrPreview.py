import numpy as np
from PIL import Image
import re

# Load your C source
with open(r"src/ImageData.cpp") as f:
    data = f.read()

# Extract all bytes
bytes_list = re.findall(r'0x([0-9A-Fa-f]{2})', data)
arr = np.array([int(x, 16) for x in bytes_list], dtype=np.uint8)

# 4 pixels per byte, 2 bits per pixel
width = 184
height = 384
num_pixels = width * height
pixels = np.zeros(num_pixels, dtype=np.uint8)

palette = [255, 170, 85, 0]  # white → light gray → dark gray → black (you can change to your e-ink colors)

pi = 0
for byte in arr:
    for shift in (6, 4, 2, 0):
        if pi >= num_pixels:
            break
        val = (byte >> shift) & 0x03
        pixels[pi] = palette[val]
        pi += 1

# reshape into (height, width)
img = Image.fromarray(pixels.reshape((height, width)), mode="L")
img = img.rotate(90, expand=True)
img.show()
