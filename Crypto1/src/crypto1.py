import os, random, string

alphabet = string.ascii_letters + string.digits + "{}_-.,/%?$!@#"
FLAG : str = os.getenv("FLAG")
assert FLAG.startswith("pascalCTF{")
assert FLAG.endswith("}")

def romanize(input_string):
    key = random.randint(1, len(alphabet) - 1)
    result = [""] * len(input_string)
    for i, c in enumerate(input_string):
        result[i] = alphabet[(alphabet.index(c) + key) % len(alphabet)]
    return "".join(result)

if __name__ == "__main__":
    result = romanize(FLAG)
    assert result != FLAG
    with open("output.txt", "w") as f:
        f.write(result)