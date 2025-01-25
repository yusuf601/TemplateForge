#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <thread>  // Untuk std::this_thread::sleep_for
#include <chrono>  // Untuk std::chrono::seconds
// ANSIEscapeCode : \033[F\033[K




void PilihanPython(int& choice){
    int ChoicePython,ChoiceReadme;
    std::string ProjectName;
    std::string Description;
    std::string fitur;
    // std::string LinkGithub;
    int CheckPython = system("python3 --version");
    for(int i = 0; i < 3; i++){
        std::cout << "Memeriksa python " << std::string(i + 1,'.') << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\033[F\033[K "; //kembali ke baris sebelumnya dan hapus baris

    }
    if(CheckPython == 0){
        std::cout << "Python terinstall di sistem anda: " << std::endl;
    }else{
        std::cout << "Python tidak terinstall di sistem anda! " << std::endl;
        std::cout << "Menginstall otomatis python!" << std::endl;
        system("sudo apt update");
        system("sudo apt install python3");
        std::cout << system("python3 --version") << std::endl;
    }
    std::cout << "Pilihan " << std::endl;
    std::cout << "1.Markdown " << std::endl;
    std::cout << "2.License " << std::endl;
    std::cout << "3.Makefile " << std::endl;
    std::cout << "4.License " << std::endl;
    std::cout << "Masukkan pilihan: ";
    std::cin >> ChoicePython;
    while(CheckPython == 0){
        if(ChoicePython == 1){
            std::cout << "Pilihan Markdown " << std::endl;
            std::cout << "1.Readme.Md " << std::endl;
            std::cout << "2.Contributing.Md " << std::endl;
            std::cout << "3.Profile Github(your_username.md) with wakatime" << std::endl;
            std::cout << "Masukkan pilihan ";
            std::cin >> ChoiceReadme;
            switch(ChoiceReadme){
                case 1: {
                    std::ofstream TemplateReadme("readme.md");
                    if(!TemplateReadme.is_open()){
                        std::cout << "Gagal Membuat file readme! " << std::endl;
                    }
                    std::cout << "Masukkan nama project: ";
                    getline(std::cin,ProjectName);
                    std::cout << "Masukkan Deskripsi: ";
                    getline(std::cin,Description);
                    std::cout << "Masukkan fitur Project: ";
                    getline(std::cin,fitur);
                    TemplateReadme << "#" << ProjectName << "\n\n";
                    TemplateReadme << "##" << Description << "\n\n";
                    TemplateReadme << "##" << fitur << "\n\n";

                    TemplateReadme.close();
                    std::cout << "FIle readme berhasil dibuat! " << std::endl;
                    break;
                }
                case 2: {
                    std::string LinkGithub;
                    std::cout << "Masukkan link Github: ";
                    getline(std::cin,LinkGithub);
                    std::ofstream TemplateContribute("Contributing.md");
                    if(!TemplateContribute.is_open()){
                        std::cout << "File Contributing.md gagal dibuat " << std::endl;
                    }
                    // Tulis konten ke file
                    TemplateContribute << "# Panduan Kontribusi\n\n";
                    TemplateContribute << "Terima kasih telah tertarik untuk berkontribusi pada proyek ini! Berikut adalah beberapa langkah dan panduan sederhana untuk membantu Anda memulai.\n\n";
                    TemplateContribute << "---\n\n";
                    TemplateContribute << "## 🛠️ Cara Berkontribusi\n\n";
                    TemplateContribute << "1. **Fork Repository**  \n";
                    TemplateContribute << "   Fork repository ini ke akun GitHub Anda sendiri dengan mengklik tombol \"Fork\".\n\n";
                    TemplateContribute << "2. **Clone Repository**  \n";
                    TemplateContribute << "   Clone repository yang telah Anda fork ke komputer lokal Anda:\n";
                    TemplateContribute << "   ```bash\n";
                    TemplateContribute << "   git clone " << LinkGithub << "\n";
                    TemplateContribute << "   cd project-name\n";
                    TemplateContribute << "   ```\n\n";
                    TemplateContribute << "3. **Buat Branch Baru**  \n";
                    TemplateContribute << "   Buat branch baru untuk fitur atau perbaikan bug Anda:\n";
                    TemplateContribute << "   ```bash\n";
                    TemplateContribute << "   git checkout -b nama-branch-anda\n";
                    TemplateContribute << "   ```\n\n";
                    TemplateContribute << "4. **Lakukan Perubahan**  \n";
                    TemplateContribute << "   Tambahkan atau ubah kode sesuai kontribusi Anda. Pastikan kode Anda:\n";
                    TemplateContribute << "   - Mematuhi standar pemrograman proyek (formatting, naming, dll.)\n";
                    TemplateContribute << "   - Tidak mengganggu fungsi yang sudah ada.\n\n";
                    TemplateContribute << "5. **Commit Perubahan**  \n";
                    TemplateContribute << "   Tambahkan deskripsi singkat namun jelas tentang perubahan Anda:\n";
                    TemplateContribute << "   ```bash\n";
                    TemplateContribute << "   git add .\n";
                    TemplateContribute << "   git commit -m \"Deskripsi singkat tentang perubahan Anda\"\n";
                    TemplateContribute << "   ```\n\n";
                    TemplateContribute << "6. **Push ke Repository Fork Anda**  \n";
                    TemplateContribute << "   Push perubahan Anda ke branch di repository fork Anda:\n";
                    TemplateContribute << "   ```bash\n";
                    TemplateContribute << "   git push origin nama-branch-anda\n";
                    TemplateContribute << "   ```\n\n";
                    TemplateContribute << "7. **Kirimkan Pull Request**  \n";
                    TemplateContribute << "   - Buka repository asli di GitHub.\n";
                    TemplateContribute << "   - Klik \"Compare & pull request\".\n";
                    TemplateContribute << "   - Jelaskan perubahan Anda secara singkat dan jelas.\n\n";
                    TemplateContribute << "---\n";
                    TemplateContribute.close();

                    std::cout << "FIle Contributing.md berhasil dibuat " << std::endl;
                    break;

                }
                case 3:{
                    std::cout << "Pastikan anda sudah membuat Repository dengan nama yang dengan username github anda! " << std::endl;
                    std::ofstream WakatimeTemplate("wakatime.yaml");
                    if(!WakatimeTemplate.is_open()){
                        std::cout << "FIle Wakatime.yaml gagal dibuat! " << std::endl;
                    }
                        // Menulis konten ke file
                    WakatimeTemplate << "name: Waka Readme\n\n";
                    WakatimeTemplate << "on:\n";
                    WakatimeTemplate << "  schedule:\n";
                    WakatimeTemplate << "    # Runs every 2 hours\n";
                    WakatimeTemplate << "    - cron: \"0 */2 * * *\"\n";
                    WakatimeTemplate << "  workflow_dispatch:\n\n";
                    WakatimeTemplate << "jobs:\n";
                    WakatimeTemplate << "  update-readme:\n";
                    WakatimeTemplate << "    name: Update Readme with Metrics\n";
                    WakatimeTemplate << "    runs-on: ubuntu-latest\n";
                    WakatimeTemplate << "    steps:\n";
                    WakatimeTemplate << "      - uses: anmol098/waka-readme-stats@master\n";
                    WakatimeTemplate << "        with:\n";
                    WakatimeTemplate << "          WAKATIME_API_KEY: ${{ secrets.WAKATIME_API_KEY }}\n";
                    WakatimeTemplate << "          GH_TOKEN: ${{ secrets.GH_TOKEN }}\n";
                    WakatimeTemplate << "          LOCALE: \"id\"  # Mengatur bahasa ke Bahasa Indonesia\n";
                    WakatimeTemplate << "          SHOW_OS: \"True\"\n";
                    WakatimeTemplate << "          SHOW_PROJECTS: \"False\"\n";
                    WakatimeTemplate << "          SHOW_LINES_OF_CODE: \"False\"\n";
                    WakatimeTemplate << "          SHOW_TOTAL_CODE_TIME: \"True\"\n";
                    WakatimeTemplate << "          COMMIT_MESSAGE: \"Updated with dev metrics\"\n";
                    WakatimeTemplate << "          COMMIT_USERNAME: \"readme-bot\"\n";
                    WakatimeTemplate << "          SHOW_PROFILE_VIEWS: \"True\"\n";
                    WakatimeTemplate << "          SHOW_COMMIT: \"False\"\n";
                    WakatimeTemplate << "          SHOW_DAYS_OF_WEEK: \"True\"\n";
                    WakatimeTemplate << "          SHOW_SHORT_INFO: \"True\"\n";

                }    

            }
        }
    }

}

int main(){
    int choice;
    std::cout << "Pilih bahasa yang anda inginkan " << std::endl;
    std::cout << "1.Python " << std::endl;
    std::cout << "2.C++ " << std::endl;
    std::cout << "Masukkan pilihan: ";
    std::cin >> choice;

    PilihanPython(choice);
    std::cin.get();
    return 0;
}