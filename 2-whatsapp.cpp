#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Message {
    int id;
    string sender;
    string text;
    bool deleted;
};

vector<Message> generateChatHistory(int n) {
    vector<Message> history;
    history.reserve(n);

    vector<string> sampleTexts = {
        "Hola", "¿Cómo estás?", "Todo bien", "Ok", "Nos vemos",
        "¿Dónde estás?", "Manda ubicación", "Ya voy", "Adiós", "👍"
    };

    for (int i = 0; i < n; i++) {
        Message msg;
        msg.id = i + 1;
        msg.sender = (i % 2 == 0 ? "Alice" : "Bob");
        msg.text = sampleTexts[i % sampleTexts.size()];
        msg.deleted = (i % 17 == 0); // cada 17 mensajes, se elimina uno
        history.push_back(msg);
    }
    return history;
}



vector<Message> CompactChatHistory(vector<Message> history) {
    vector<Message> write = {}; // va a recibir los mensajes no nulos
    vector<Message> deleted = {}; // va a recibir los mensajes que si son nulos

    for (int i = 0; i < history.size(); i++) {
        if (history[i].deleted != true) { // si no son nulos los agrega al write
            write.push_back(history[i]);
        } else {
            deleted.push_back(history[i]); // si son nulos los agrega a los deleted
        }
    }

    for (int i = 0; i < deleted.size(); i++) {
        write.push_back(deleted[i]); // agrega al write los no nulos al final
    }

    return write;

}





int main() {
    vector<Message> chat = generateChatHistory(5000);

    // Mostrar solo los primeros 10 
    for (int i = 0; i < 10; i++) {
        cout << chat[i].id << " [" << chat[i].sender << "]: "
             << chat[i].text
             << (chat[i].deleted ? " (deleted)" : "")
             << endl;
    }

    vector<Message> new_chat = CompactChatHistory(chat);
    for (int i = 0; i < new_chat.size(); i++) {
        cout << new_chat[i].id << " [" << new_chat[i].sender << "]: "
             << new_chat[i].text
             << (new_chat[i].deleted ? " (deleted)" : "")
             << endl;
    }

    cout << "Total mensajes generados: " << chat.size() << endl;
}