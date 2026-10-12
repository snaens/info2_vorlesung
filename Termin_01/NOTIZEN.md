## NICHT KLAUSURRELEVANT ##

- nutzen des Debuggers um Variable im Stack zu modifizieren
- continue = c
- insert addresse der showSecretInfo() fkt. in Rücksprungaddresse einer anderen fkt.

# Stack

| Addr | Wert      |
| ---- | --------- |
| e640 | buffer[0] |
| e641 | buffer[1] |
|  ... |  ...      |
| e660 | 10        |
|  ... |  ...      |
| e680 | 42        |

- Wächst nach oben/unten je nach Prozessor
- Buffer overflow: einfach out of range gehen ;)

- was ist auf amd64 anders?

- info frame
pc program counter
sp stack pointer
rip return instruction pointer
rbp 
