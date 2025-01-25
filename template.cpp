#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <thread>  // Untuk std::this_thread::sleep_for
#include <chrono>  // Untuk std::chrono::seconds
// ANSIEscapeCode : \033[F\033[K




void PilihanPython(int& choice){
    int ChoicePython,ChoiceReadme,ChoiceLicense;
    std::string ProjectName;
    std::string Description;
    std::string fitur;
    // std::string LinkGithub;
    for(int i = 0; i < 3; i++){
        std::cout << "Memeriksa python " << std::string(i + 1,'.') << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\033[F\033[K "; //kembali ke baris sebelumnya dan hapus baris

    }
    int CheckPython = system("python3 --version");
    // CheckPython = system("python3 --version");
    // std::cout << "Versi Python: " << CheckPython << std::endl;
    if(CheckPython == 0){
        std::cout << "Python terinstall di sistem anda: " << std::endl;
        system("python3 --version");
    }else{
        std::cout << "Python tidak terinstall di sistem anda! " << std::endl;
        std::cout << "Menginstall otomatis python!" << std::endl;
        system("sudo apt update");
        system("sudo apt install python3");
        std::cout << system("python3 --version") << std::endl;
    }
    while(CheckPython == 0){
        std::cout << "Pilihan " << std::endl;
        std::cout << "1.Markdown " << std::endl;
        std::cout << "2.License " << std::endl;
        std::cout << "3.Makefile " << std::endl;
        std::cout << "4.License " << std::endl;
        std::cout << "Masukkan pilihan: ";
        std::cin >> ChoicePython;
        system("clear");
        if(ChoicePython == 1){
            std::cout << "Pilihan Markdown " << std::endl;
            std::cout << "1.Readme.Md " << std::endl;
            std::cout << "2.Contributing.Md " << std::endl;
            std::cout << "3.Profile Github(your_username.md) with wakatime" << std::endl;
            std::cout << "Masukkan pilihan ";
            std::cin >> ChoiceReadme;
            system("clear");
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
                    break;
                }   
                break;
                default:
                    std::cout << "Pilihan yang anda masukkan salah " << std::endl;
                    break; 

            }
        if(CheckPython == 2){
            std::cout << "Pilihan License " << std::endl;
            std::cout << "1.MIT " << std::endl;
            std::cout << "2.Apache " << std::endl;
            std::cout << "Masukkan pilihan: ";
            std::cin >> ChoiceLicense;
            switch(ChoiceLicense){
                case 1: {
                    std::string name,year;
                    std::ofstream MitTemplate("License.md");
                    if(!MitTemplate.is_open()){
                        std::cout << "License.md gagal dibuat! " << std::endl;
                    }
                    std::cout << "Masukkan nama: ";
                    getline(std::cin,name);
                    std::cout << "Masukkan tahun: ";
                    getline(std::cin,year);
                    // Menulis konten lisensi MIT ke file
                    MitTemplate << "The MIT License (MIT)\n\n";
                    MitTemplate << "Copyright (c) " << year << " " << name << "\n\n";
                    MitTemplate << "Permission is hereby granted, free of charge, to any person obtaining a copy\n";
                    MitTemplate << "of this software and associated documentation files (the \"Software\"), to deal\n";
                    MitTemplate << "in the Software without restriction, including without limitation the rights\n";
                    MitTemplate << "to use, copy, modify, merge, publish, distribute, sublicense, and/or sell\n";
                    MitTemplate << "copies of the Software, and to permit persons to whom the Software is\n";
                    MitTemplate << "furnished to do so, subject to the following conditions:\n\n";
                    MitTemplate << "The above copyright notice and this permission notice shall be included in\n";
                    MitTemplate << "all copies or substantial portions of the Software.\n\n";
                    MitTemplate << "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n";
                    MitTemplate << "IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n";
                    MitTemplate << "FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n";
                    MitTemplate << "AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n";
                    MitTemplate << "LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n";
                    MitTemplate << "OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN\n";
                    MitTemplate << "THE SOFTWARE.\n";
                    MitTemplate.close();

                    std::cout << "File License.md berhasil dibuat! " << std::endl;
                }   break;
                case 2: {
                    std::string name,year;
                    std::ofstream ApacheTemplate("License.md");
                    if(!ApacheTemplate.is_open()){
                        std::cout << "File License.md gagal dibuat! " << std::endl;
                    }
                    std::cout << "Masukkan nama: ";
                    getline(std::cin,name);
                    std::cout << "Masukkan tahun: ";
                    getline(std::cin,year);
                    ApacheTemplate << "Apache License\n";
                    ApacheTemplate << "Version 2.0, January 2004\n";
                    ApacheTemplate << "http://www.apache.org/licenses/\n\n";
                    ApacheTemplate << "TERMS AND CONDITIONS FOR USE, REPRODUCTION, AND DISTRIBUTION\n\n";
                    ApacheTemplate << "1. Definitions.\n\n";
                    ApacheTemplate << "   \"License\" shall mean the terms and conditions for use, reproduction,\n";
                    ApacheTemplate << "   and distribution as defined by Sections 1 through 9 of this document.\n\n";
                    ApacheTemplate << "   \"Licensor\" shall mean the copyright owner or entity authorized by\n";
                    ApacheTemplate << "   the copyright owner that is granting the License.\n\n";
                    ApacheTemplate << "   \"Legal Entity\" shall mean the union of the acting entity and all\n";
                    ApacheTemplate << "   other entities that control, are controlled by, or are under common\n";
                    ApacheTemplate << "   control with that entity. For the purposes of this definition,\n";
                    ApacheTemplate << "   \"control\" means (i) the power, direct or indirect, to cause the\n";
                    ApacheTemplate << "   direction or management of such entity, whether by contract or\n";
                    ApacheTemplate << "   otherwise, or (ii) ownership of fifty percent (50%) or more of the\n";
                    ApacheTemplate << "   outstanding shares, or (iii) beneficial ownership of such entity.\n\n";
                    ApacheTemplate << "   \"You\" (or \"Your\") shall mean an individual or Legal Entity\n";
                    ApacheTemplate << "   exercising permissions granted by this License.\n\n";
                    ApacheTemplate << "   \"Source\" form shall mean the preferred form for making modifications,\n";
                    ApacheTemplate << "   including but not limited to software source code, documentation\n";
                    ApacheTemplate << "   source, and configuration files.\n\n";
                    ApacheTemplate << "   \"Object\" form shall mean any form resulting from mechanical\n";
                    ApacheTemplate << "   transformation or translation of a Source form, including but\n";
                    ApacheTemplate << "   not limited to compiled object code, generated documentation,\n";
                    ApacheTemplate << "   and conversions to other media types.\n\n";
                    ApacheTemplate << "   \"Work\" shall mean the work of authorship, whether in Source or\n";
                    ApacheTemplate << "   Object form, made available under the License, as indicated by a\n";
                    ApacheTemplate << "   copyright notice that is included in or attached to the work\n";
                    ApacheTemplate << "   (an example is provided in the Appendix below).\n\n";
                    ApacheTemplate << "   \"Derivative Works\" shall mean any work, whether in Source or Object\n";
                    ApacheTemplate << "   form, that is based on (or derived from) the Work and for which the\n";
                    ApacheTemplate << "   editorial revisions, annotations, elaborations, or other modifications\n";
                    ApacheTemplate << "   represent, as a whole, an original work of authorship. For the purposes\n";
                    ApacheTemplate << "   of this License, Derivative Works shall not include works that remain\n";
                    ApacheTemplate << "   separable from, or merely link (or bind by name) to the interfaces of,\n";
                    ApacheTemplate << "   the Work and Derivative Works thereof.\n\n";
                    ApacheTemplate << "   \"Contribution\" shall mean any work of authorship, including\n";
                    ApacheTemplate << "   the original version of the Work and any modifications or additions\n";
                    ApacheTemplate << "   to that Work or Derivative Works thereof, that is intentionally\n";
                    ApacheTemplate << "   submitted to Licensor for inclusion in the Work by the copyright owner\n";
                    ApacheTemplate << "   or by an individual or Legal Entity authorized to submit on behalf of\n";
                    ApacheTemplate << "   the copyright owner. For the purposes of this definition, \"submitted\"\n";
                    ApacheTemplate << "   means any form of electronic, verbal, or written communication sent\n";
                    ApacheTemplate << "   to the Licensor or its representatives, including but not limited to\n";
                    ApacheTemplate << "   communication on electronic mailing lists, source code control systems,\n";
                    ApacheTemplate << "   and issue tracking systems that are managed by, or on behalf of, the\n";
                    ApacheTemplate << "   Licensor for the purpose of discussing and improving the Work, but\n";
                    ApacheTemplate << "   excluding communication that is conspicuously marked or otherwise\n";
                    ApacheTemplate << "   designated in writing by the copyright owner as \"Not a Contribution.\"\n\n";
                    ApacheTemplate << "   \"Contributor\" shall mean Licensor and any individual or Legal Entity\n";
                    ApacheTemplate << "   on behalf of whom a Contribution has been received by Licensor and\n";
                    ApacheTemplate << "   subsequently incorporated within the Work.\n\n";
                    ApacheTemplate << "2. Grant of Copyright License. Subject to the terms and conditions of\n";
                    ApacheTemplate << "   this License, each Contributor hereby grants to You a perpetual,\n";
                    ApacheTemplate << "   worldwide, non-exclusive, no-charge, royalty-free, irrevocable\n";
                    ApacheTemplate << "   copyright license to reproduce, prepare Derivative Works of,\n";
                    ApacheTemplate << "   publicly display, publicly perform, sublicense, and distribute the\n";
                    ApacheTemplate << "   Work and such Derivative Works in Source or Object form.\n\n";
                    ApacheTemplate << "3. Grant of Patent License. Subject to the terms and conditions of\n";
                    ApacheTemplate << "   this License, each Contributor hereby grants to You a perpetual,\n";
                    ApacheTemplate << "   worldwide, non-exclusive, no-charge, royalty-free, irrevocable\n";
                    ApacheTemplate << "   (except as stated in this section) patent license to make, have made,\n";
                    ApacheTemplate << "   use, offer to sell, sell, import, and otherwise transfer the Work,\n";
                    ApacheTemplate << "   where such license applies only to those patent claims licensable\n";
                    ApacheTemplate << "   by such Contributor that are necessarily infringed by their\n";
                    ApacheTemplate << "   Contribution(s) alone or by combination of their Contribution(s)\n";
                    ApacheTemplate << "   with the Work to which such Contribution(s) was submitted. If You\n";
                    ApacheTemplate << "   institute patent litigation against any entity (including a\n";
                    ApacheTemplate << "   cross-claim or counterclaim in a lawsuit) alleging that the Work\n";
                    ApacheTemplate << "   or a Contribution incorporated within the Work constitutes direct\n";
                    ApacheTemplate << "   or contributory patent infringement, then any patent licenses\n";
                    ApacheTemplate << "   granted to You under this License for that Work shall terminate\n";
                    ApacheTemplate << "   as of the date such litigation is filed.\n\n";
                    ApacheTemplate << "4. Redistribution. You may reproduce and distribute copies of the\n";
                    ApacheTemplate << "   Work or Derivative Works thereof in any medium, with or without\n";
                    ApacheTemplate << "   modifications, and in Source or Object form, provided that You\n";
                    ApacheTemplate << "   meet the following conditions:\n\n";
                    ApacheTemplate << "   (a) You must give any other recipients of the Work or\n";
                    ApacheTemplate << "       Derivative Works a copy of this License; and\n\n";
                    ApacheTemplate << "   (b) You must cause any modified files to carry prominent notices\n";
                    ApacheTemplate << "       stating that You changed the files; and\n\n";
                    ApacheTemplate << "   (c) You must retain, in the Source form of any Derivative Works\n";
                    ApacheTemplate << "       that You distribute, all copyright, patent, trademark, and\n";
                    ApacheTemplate << "       attribution notices from the Source form of the Work,\n";
                    ApacheTemplate << "       excluding those notices that do not pertain to any part of\n";
                    ApacheTemplate << "       the Derivative Works; and\n\n";
                    ApacheTemplate << "   (d) If the Work includes a \"NOTICE\" text file as part of its\n";
                    ApacheTemplate << "       distribution, then any Derivative Works that You distribute must\n";
                    ApacheTemplate << "       include a readable copy of the attribution notices contained\n";
                    ApacheTemplate << "       within such NOTICE file, excluding those notices that do not\n";
                    ApacheTemplate << "       pertain to any part of the Derivative Works, in at least one\n";
                    ApacheTemplate << "       of the following places: within a NOTICE text file distributed\n";
                    ApacheTemplate << "       as part of the Derivative Works; within the Source form or\n";
                    ApacheTemplate << "       documentation, if provided along with the Derivative Works; or,\n";
                    ApacheTemplate << "       within a display generated by the Derivative Works, if and\n";
                    ApacheTemplate << "       wherever such third-party notices normally appear. The contents\n";
                    ApacheTemplate << "       of the NOTICE file are for informational purposes only and\n";
                    ApacheTemplate << "       do not modify the License. You may add Your own attribution\n";
                    ApacheTemplate << "       notices within Derivative Works that You distribute, alongside\n";
                    ApacheTemplate << "       or as an addendum to the NOTICE text from the Work, provided\n";
                    ApacheTemplate << "       that such additional attribution notices cannot be construed\n";
                    ApacheTemplate << "       as modifying the License.\n\n";
                    ApacheTemplate << "   You may add Your own copyright statement to Your modifications and\n";
                    ApacheTemplate << "   may provide additional or different license terms and conditions\n";
                    ApacheTemplate << "   for use, reproduction, or distribution of Your modifications, or\n";
                    ApacheTemplate << "   for any such Derivative Works as a whole, provided Your use,\n";
                    ApacheTemplate << "   reproduction, and distribution of the Work otherwise complies with\n";
                    ApacheTemplate << "   the conditions stated in this License.\n\n";
                    ApacheTemplate << "5. Submission of Contributions. Unless You explicitly state otherwise,\n";
                    ApacheTemplate << "   any Contribution intentionally submitted for inclusion in the Work\n";
                    ApacheTemplate << "   by You to the Licensor shall be under the terms and conditions of\n";
                    ApacheTemplate << "   this License, without any additional terms or conditions.\n";
                    ApacheTemplate << "   Notwithstanding the above, nothing herein shall supersede or modify\n";
                    ApacheTemplate << "   the terms of any separate license agreement you may have executed\n";
                    ApacheTemplate << "   with Licensor regarding such Contributions.\n\n";
                    ApacheTemplate << "6. Trademarks. This License does not grant permission to use the trade\n";
                    ApacheTemplate << "   names, trademarks, service marks, or product names of the Licensor,\n";
                    ApacheTemplate << "   except as required for reasonable and customary use in describing the\n";
                    ApacheTemplate << "   origin of the Work and reproducing the content of the NOTICE file.\n\n";
                    ApacheTemplate << "7. Disclaimer of Warranty. Unless required by applicable law or\n";
                    ApacheTemplate << "   agreed to in writing, Licensor provides the Work (and each\n";
                    ApacheTemplate << "   Contributor provides its Contributions) on an \"AS IS\" BASIS,\n";
                    ApacheTemplate << "   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or\n";
                    ApacheTemplate << "   implied, including, without limitation, any warranties or conditions\n";
                    ApacheTemplate << "   of TITLE, NON-INFRINGEMENT, MERCHANTABILITY, or FITNESS FOR A\n";
                    ApacheTemplate << "   PARTICULAR PURPOSE. You are solely responsible for determining the\n";
                    ApacheTemplate << "   appropriateness of using or redistributing the Work and assume any\n";
                    ApacheTemplate << "   risks associated with Your exercise of permissions under this License.\n\n";
                    ApacheTemplate << "8. Limitation of Liability. In no event and under no legal theory,\n";
                    ApacheTemplate << "   whether in tort (including negligence), contract, or otherwise,\n";
                    ApacheTemplate << "   unless required by applicable law (such as deliberate and grossly\n";
                    ApacheTemplate << "   negligent acts) or agreed to in writing, shall any Contributor be\n";
                    ApacheTemplate << "   liable to You for damages, including any direct, indirect, special,\n";
                    ApacheTemplate << "   incidental, or consequential damages of any character arising as a\n";
                    ApacheTemplate << "   result of this License or out of the use or inability to use the\n";
                    ApacheTemplate << "   Work (including but not limited to damages for loss of goodwill,\n";
                    ApacheTemplate << "   work stoppage, computer failure or malfunction, or any and all\n";
                    ApacheTemplate << "   other commercial damages or losses), even if such Contributor\n";
                    ApacheTemplate << "   has been advised of the possibility of such damages.\n\n";
                    ApacheTemplate << "9. Accepting Warranty or Additional Liability. While redistributing\n";
                    ApacheTemplate << "   the Work or Derivative Works thereof, You may choose to offer,\n";
                    ApacheTemplate << "   and charge a fee for, acceptance of support, warranty, indemnity,\n";
                    ApacheTemplate << "   or other liability obligations and/or rights consistent with this\n";
                    ApacheTemplate << "   License. However, in accepting such obligations, You may act only\n";
                    ApacheTemplate << "   on Your own behalf and on Your sole responsibility, not on behalf\n";
                    ApacheTemplate << "   of any other Contributor, and only if You agree to indemnify,\n";
                    ApacheTemplate << "   defend, and hold each Contributor harmless for any liability\n";
                    ApacheTemplate << "   incurred by, or claims asserted against, such Contributor by reason\n";
                    ApacheTemplate << "   of your accepting any such warranty or additional liability.\n\n";
                    ApacheTemplate << "END OF TERMS AND CONDITIONS\n\n";
                    ApacheTemplate << "APPENDIX: How to apply the Apache License to your work.\n\n";
                    ApacheTemplate << "   To apply the Apache License to your work, attach the following\n";
                    ApacheTemplate << "   boilerplate notice, with the fields enclosed by brackets \"[]\"\n";
                    ApacheTemplate << "   replaced with your own identifying information. (Don't include\n";
                    ApacheTemplate << "   the brackets!)  The text should be enclosed in the appropriate\n";
                    ApacheTemplate << "   comment syntax for the file format. We also recommend that a\n";
                    ApacheTemplate << "   file or class name and description of purpose be included on the\n";
                    ApacheTemplate << "   same \"printed page\" as the copyright notice for easier\n";
                    ApacheTemplate << "   identification within third-party archives.\n\n";
                    ApacheTemplate << "Copyright [" << year << "] [" << name << "]\n\n";
                    ApacheTemplate << "Licensed under the Apache License, Version 2.0 (the \"License\");\n";
                    ApacheTemplate << "you may not use this file except in compliance with the License.\n";
                    ApacheTemplate << "You may obtain a copy of the License at\n\n";
                    ApacheTemplate << "    http://www.apache.org/licenses/LICENSE-2.0\n\n";
                    ApacheTemplate << "Unless required by applicable law or agreed to in writing, software\n";
                    ApacheTemplate << "distributed under the License is distributed on an \"AS IS\" BASIS,\n";
                    ApacheTemplate << "WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.\n";
                    ApacheTemplate << "See the License for the specific language governing permissions and\n";
                    ApacheTemplate << "limitations under the License.\n";
                }
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
    system("clear");

    PilihanPython(choice);
    std::cin.get();
    return 0;
}