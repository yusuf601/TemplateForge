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