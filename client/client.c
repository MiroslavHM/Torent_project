#include <stdio.h>
#include <string.h>
#include "../shared/common.h"

int main() {
    TorrentRequest request;

    printf("=== Торент заявка ===\n");

    printf("Потребителско име: ");
    fgets(request.username, MAX_NAME_LEN, stdin);
    request.username[strcspn(request.username, "\n")] = '\0';

    printf("Име на торента: ");
    fgets(request.torrent_name, MAX_TORRENT_NAME, stdin);
    request.torrent_name[strcspn(request.torrent_name, "\n")] = '\0';

    printf("Път за изтегляне: ");
    fgets(request.download_path, MAX_PATH_LEN, stdin);
    request.download_path[strcspn(request.download_path, "\n")] = '\0';

    printf("Източник (URL): ");
    fgets(request.source_url, MAX_URL_LEN, stdin);
    request.source_url[strcspn(request.source_url, "\n")] = '\0';

    // Показваме въведената заявка
    printf("\nВъведена заявка:\n");
    printf("Потребител: %s\n", request.username);
    printf("Торент: %s\n", request.torrent_name);
    printf("Път: %s\n", request.download_path);
    printf("URL: %s\n", request.source_url);

    // Записваме заявката във файл request.txt
    FILE *file = fopen("data/request.txt", "w");
    if (file == NULL) {
        perror("Грешка при запис на заявката");
        return 1;
    }

    fprintf(file, "%s;%s;%s;%s\n",
            request.username,
            request.torrent_name,
            request.download_path,
            request.source_url);

    fclose(file);

    printf("\nЗаявката беше записана в 'request.txt'\n");

    return 0;
}
