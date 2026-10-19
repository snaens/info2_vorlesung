#include "namesarchive.h"

#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#define MAX_NAMES 99


// static -> modul-globale variable (sonst wäre sie in allen Dateien vorhanden)
static char names[MAX_NAMES][MAX_NAME_LEN];
// position of last modified name
static int name_pos = 0;

int addName(const char *name) {
    if (name_pos < MAX_NAMES) {
        printf("%s\n", name);
        strncpy(names[name_pos++], name, MAX_NAME_LEN);
        return 1;
    }
    return 0;
}

int removeName(const char *name) {
    for (int i = 0; i < name_pos; i++) {
        if (strncmp(names[i], name, MAX_NAME_LEN) == 0) {
            // shift all following entries up one -> overwrite entry to be deleted
            for (int j = i + 1; j <= name_pos; j++) {
                strncpy(names[j - 1], names[j], MAX_NAME_LEN);
            }
            name_pos--;
            return 1;
        }
    }
    return 0;
}

void printNames() {
    for (int i = 0; i < name_pos; i++) {
        printf("%s\n", names[i]);
    }
}

void clearArchive() {
    for (int i = 0; i < name_pos; i++) {
        strncpy(names[i], "", MAX_NAME_LEN);
    }
    name_pos = 0;
}

// Lädt den Inhalt einer Textdatei zeilenweise in das Archiv. Gibt 1 bei Erfolg zurück.
int loadArchive(const char *path) {
    FILE *f = fopen(path, "r");
    if (f != NULL) {
        // clear old data
        clearArchive();

        char line[MAX_NAME_LEN];
        while (fgets(line, MAX_NAME_LEN, f) != NULL) {
            // cut trailing newline
            line[strcspn(line, "\n")] = '\0';
            addName(line);
        }
        fclose(f);
        return 1;
    }
    return 0;
}

// Speichert das Archiv zeilenweise in einer Textdatei. Gibt 1 bei Erfolg zurück.
int saveArchive(const char *path) {
    FILE *f = fopen(path, "w");
    if (f) {
        for (int i = 0; i < name_pos; i++) {
            fprintf(f, "%s\n", names[i]);
        }
        fclose(f);
        return 1;
    }
    return 0;
}
