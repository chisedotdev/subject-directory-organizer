#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

int lineFileCounter(std::string file_name)
{
	std::ifstream file(file_name);
	std::string line{};
	int line_counter{};

	if(file.is_open()) {
		while(std::getline(file, line)) {
			line_counter++;
		}
		
		file.close();
		return line_counter;
	} else {
		std::cerr << "Unable to get the number of lines." << '\n';
		return 1;
	}
}

std::vector<std::string> getSubjectNames(std::string file_path)
{
	std::vector<std::string> subjects{};

	std::ifstream file(file_path);

	if(file.is_open()) {
		std::string line{};

		while(std::getline(file, line)) {
			subjects.push_back(line);
		}
	} else {
		std::cerr << "Unable to open file." << '\n';
	}

	return subjects;
}

void createDirectories(std::vector<std::string> subjects, std::string custom_path, int number_of_subjects)
{
	for(int i = 0; i < number_of_subjects; i++) {
		std::string subject_path = custom_path + "/" + subjects[i];
		std::filesystem::create_directories(subject_path);
		std::filesystem::create_directories(subject_path + "/Prelim");
		std::filesystem::create_directories(subject_path + "/Prelim" + "/Assignments - Projects - Quizzes");
		std::filesystem::create_directories(subject_path + "/Prelim" + "/Notes - Reviewers");

		std::filesystem::create_directories(subject_path + "/Midterm");
		std::filesystem::create_directories(subject_path + "/Midterm" + "/Assignments - Projects - Quizzes");
		std::filesystem::create_directories(subject_path + "/Midterm" + "/Notes - Reviewers");

		std::filesystem::create_directories(subject_path + "/Finals");
		std::filesystem::create_directories(subject_path + "/Finals" + "/Assignments - Projects - Quizzes");
		std::filesystem::create_directories(subject_path + "/Finals" + "/Notes - Reviewers");
	}
}

int main()
{
    std::string custom_path{};
    std::cout << "Enter custom path (e.g., C:\\Users\\username\\Desktop): ";
    std::getline(std::cin, custom_path);

    if (!std::filesystem::exists(custom_path)) {
        std::cerr << "The provided custom path does not exist: " << custom_path << '\n';
        return 1;
    }

    std::string file_path{};
    std::cout << "Enter file path (e.g., C:\\Users\\username\\Desktop\\subject_names.txt): ";
    std::getline(std::cin, file_path);

    if (!std::filesystem::exists(file_path)) {
        std::cerr << "The provided file path does not exist: " << file_path << '\n';
        return 1;
    }

	int number_of_subjects = lineFileCounter(file_path);

	std::vector<std::string> subjects = getSubjectNames(file_path);
	if(number_of_subjects > 0) {
		std::cout << "Names of subject have been found. Proceeding to the next step." << '\n';
		
		createDirectories(subjects, custom_path, number_of_subjects);

		std::cout << "Done creating directories and sub-directories." << '\n';
		std::cout << "Location: " << custom_path << '\n';
	} else {
		std::cerr << "No subjects have been found." << '\n';
	}

	return 0;
}
