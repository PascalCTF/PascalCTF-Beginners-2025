import signal, os

SENTENCES = [
    b"Elia recently passed away, how will we be able to live without a sysadmin?!!?",
    os.urandom(42),
    os.getenv('FLAG', 'pascalCTF{m4by3_1_sh0uld_ch3ck_th3_t0t4l_numb3r_0f_ONES}').encode()
]

def generate(seeds: list[int], idx: int) -> list[int]:
    result = []
    if idx < 0 or idx > 2:
        return result
    encoded = int.from_bytes(SENTENCES[idx], 'big')
    for bet in seeds:
        # why you're using 1s when 0s exist
        if bet.bit_count() > 40:
            continue
        result.append(encoded & bet)
    
    return result

def menu():
    print("Welcome to the italian MindBlowing game!")
    print("1. Generate numbers")
    print("2. Exit")
    print()

    return input('> ')

def handler(signum, frame):
    print("Time's up!")
    exit()

if __name__ == '__main__':
    signal.signal(signal.SIGALRM, handler)
    signal.alarm(300)
    while True:
        choice = menu()

        try:
            if choice == '1':
                idx = int(input('Gimme the index of a sentence: '))
                seeds_num = int(input('Gimme the number of seeds: '))
                seeds = []
                for _ in range(seeds_num):
                    seeds.append(int(input(f'Seed of the number {_+1}: ')))
                print(f"Result: {generate(seeds, idx)}")
            elif choice == '2':
                break
            else:
                print("Wrong choice (。_。)")
        except:
            print("Boh ㄟ( ▔, ▔ )ㄏ")