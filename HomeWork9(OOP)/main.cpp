#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

class Hospital {
private:
    std::vector<std::string> patients;
    size_t capacity;

public:
    
    Hospital() : capacity(10) {}

    
    Hospital(std::initializer_list<std::string> patientList, size_t cap = 10) : patients(patientList), capacity(cap) {
        if (patients.size() > capacity) {
            throw std::overflow_error("Переполнен.");
        }
    }

  
    Hospital(const Hospital& other) : patients(other.patients), capacity(other.capacity) {}

   
    void put(const std::string& patientName) {
        if (patients.size() < capacity) {
            patients.push_back(patientName);
        }
        else {
            throw std::overflow_error("Переполнен.");
        }
    }

    
    void discharge(size_t index) {
        if (index < patients.size()) {
            patients.erase(patients.begin() + index);
        }
        else {
            throw std::out_of_range("Индекс вне диапазона");
        }
    }

    
    int find(const std::string& patientName) {
        for (auto it = patients.begin(); it != patients.end(); ++it) {
            if (*it == patientName) {
                return std::distance(patients.begin(), it);
            }
        }
        return -1; 
    }

    
    std::string report() {
        std::string result;
        for (size_t i = 0; i < patients.size(); ++i) {
            result += patients[i];
            if (i != patients.size() - 1) {
                result += ", ";
            }
        }
        return result;
    }

    
    size_t getPatientCount() const {
        return patients.size();
    }

    
    size_t getCapacity() const {
        return capacity;
    }
};

int main() {
    setlocale(0, "Russian");
    Hospital hospital({ "Robert Downey Jr.", "DeadPool", "Peter" }, 5);

    hospital.put("Thanos");
    hospital.put("Thor");
    
    

    std::cout << "Пациенты: " << hospital.report() << std::endl;
    std::cout << hospital.getPatientCount() << std::endl;
    
    hospital.discharge(0);
    
    std::cout << hospital.find("DeadPool") << std::endl;
    
    std::cout << "Оставшиеся пациенты после выписки: " << hospital.report() << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    

    std::cout << hospital.getPatientCount() << std::endl;
    std::cout << hospital.getCapacity() << std::endl;


    return 0;
}