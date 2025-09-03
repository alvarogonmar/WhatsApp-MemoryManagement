# WhatsappMessages.cpp

This project demonstrates a simple simulation of WhatsApp chat message management using C++ and the two-pointer technique.

## Description

- The program generates a chat history with a specified number of messages.
- Every 17th message is marked as deleted (simulating message deletion in a chat app).
- The `compactHistory` function uses the two-pointer technique to move all non-deleted messages to the front of the vector, and places the deleted messages (represented as `[NULL]`) at the end.
- This approach efficiently compacts the chat history in-place, minimizing extra memory usage.

## How it works

1. **Message Generation:**
   - The `generateChatHistory` function creates a vector of messages, marking every 17th message as deleted.
2. **Compaction:**
   - The `compactHistory` function iterates through the chat history with two pointers:
     - One pointer (`i`) scans all messages.
     - The other pointer (`j`) keeps track of the position to place the next non-deleted message.
   - After all non-deleted messages are moved to the front, the remaining positions are filled with deleted messages (`[NULL]`).

## Example Output

Before compaction:

```
1 [Alice]: Hola
2 [Bob]: ¿Cómo estás?
...
17 [Alice]: Hola (deleted)
...
```

After compaction:

```
1 [Alice]: Hola
2 [Bob]: ¿Cómo estás?
...
17 [Alice]: [NULL] (deleted)
...
```

## Usage

Compile and run the program:

```sh
g++ 1-WhatsappMessages.cpp -o 1-WhatsappMessages
./1-WhatsappMessages
```

## Key Concepts

- Two-pointer technique
- In-place array/vector modification
- Simulating message deletion and compaction

---
