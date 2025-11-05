from PIL import Image
import numpy as np
import sys

# --- CONFIG ---
WIDTH, HEIGHT = 384, 184  # As per EPD_3in5g.h
INPUT = sys.argv[1]
OUTPUT = "Image4color.c"

# --- Load and prepare image ---
im = Image.open(INPUT).convert("RGB").resize((WIDTH, HEIGHT))

# Optional: rotate if you want landscape display
im = im.rotate(270, expand=True)

# --- 2-bit color mapping ---
# 00=Black, 01=White, 10=Yellow, 11=Red
def rgb_to_2bit(r, g, b):

    if r < 60 and g < 60 and b < 60:
        return 0b00  # black
    else:
        return 0b01 # white
    # elif r > 200 and g > 200 and b > 200:
    #     return 0b01  # white
    # elif r > 200 and g > 180 and b < 80:
    #     return 0b10  # yellow
    # elif r > 180 and g < 80 and b < 80:
    #     return 0b11  # red
    # else:
    #     # fallback based on luminance
    #     gray = (r * 0.3 + g * 0.59 + b * 0.11)
    #     return 0b01 if gray > 127 else 0b00

pixels = np.array(im)
HEIGHT, WIDTH = pixels.shape[:2]
data = []
byte = 0
count = 0

for y in range(HEIGHT):
    for x in range(WIDTH):
        bits = rgb_to_2bit(*pixels[y, x])
        byte = (byte << 2) | bits
        count += 1
        if count == 4:
            data.append(byte)
            byte = 0
            count = 0

# Pad leftover pixels
if count != 0:
    data.append(byte << (8 - count * 2))

# --- Save to C array ---
with open(OUTPUT, "w") as f:
    f.write(f"const unsigned char Image4color[{len(data)}] = {{\n")
    for i, b in enumerate(data):
        f.write(f"0x{b:02X},")
        if (i + 1) % 16 == 0:
            f.write("\n")
    f.write("};\n")

print(f"Generated {len(data)} bytes")
