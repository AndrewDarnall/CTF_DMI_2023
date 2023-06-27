import binascii
from pwn import xor

with open("output.txt") as h:
    encrypted_test = binascii.unhexlify(h.readline().strip())
    encrypted_flag = binascii.unhexlify(h.readline().strip())
    # encrypted_test = h.readline().strip()
    # encrypted_flag = h.readline().strip()

# print(f"{encrypted_test=}")
# print(f"{encrypted_flag=}")

test = b"No right of private conversation was enumerated in the Constituation. I don't suppose it occurred to anyone at the time that it could be prevented."

blob = xor(encrypted_test, encrypted_flag)
# print(f"{blob=}")
flag = xor(blob, test)
print(f"{flag=}")
