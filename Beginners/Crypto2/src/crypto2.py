import os, dotenv

dotenv.load_dotenv()
SENTENCES = [
    b"Elia recently passed away, how will we be able to live without a sysadmin?!!?",
    os.urandom(42),
    os.getenv('FLAG', 'pascalCTF{m4by3_1_sh0uld_ch3ck_th3_t0t4l_numb3r_0f_ONES}').encode()
]
assert int.from_bytes(SENTENCES[2], 'big').bit_length() == 447

def play(data: list[int], idx: int) -> list[int]:
    result = [0]
    if idx < 0 or idx > 2:
        return result
    encoded = int.from_bytes(SENTENCES[idx], 'big')
    for mask in data:
        # why you're using 1s when 0s exist
        if mask.bit_count() > 40:
            continue
        result.append(encoded & mask)
    
    return result

def menu():
    print("Welcome to the mindBlowing game!")
    print("1. Play the game")
    print("2. Exit")
    print()

    return input('> ')

if __name__ == '__main__':
    while True:
        choice = menu()

        try:
            if choice == '1':
                idx = int(input('Gimme a number in the range [0; 2]: '))
                datas = int(input('Gimme the number of your bets: '))
                data = []
                for _ in range(datas):
                    data.append(int(input(f'Gimme the bet {_+1}: ')))
                print(f"Result: {play(data, idx)}")
            elif choice == '2':
                break
            else:
                print("Wrong choice (。_。)")
        except:
            print("Boh ㄟ( ▔, ▔ )ㄏ")