from base64 import b64encode
import random, dotenv, os

dotenv.load_dotenv()
FLAG : str = os.get_env("FLAG")
assert FLAG.startswith(b"pascalCTF{")
assert FLAG.endswith(b"}")

def encode(input_string):
    if random.randint(0, 1) == 0:
        return b64encode(input_string)
    else:
        return input_string.hex().encode()
    
if __name__ == "__main__":
    for i in range(10):
        FLAG = encode(FLAG)
    print(FLAG.decode())