#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>

// Клас Vector
class Vector {
private:
    double x;
    double y;
    double z;

public:
    Vector(double xVal, double yVal, double zVal) : x(xVal), y(yVal), z(zVal) {}

    double getMagnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    double dotProduct(const Vector& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    Vector add(const Vector& other) const {
        return Vector(x + other.x, y + other.y, z + other.z);
    }

    Vector subtract(const Vector& other) const {
        return Vector(x - other.x, y - other.y, z - other.z);
    }

    Vector multiply(double scalar) const {
        return Vector(x * scalar, y * scalar, z * scalar);
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    double getZ() const {
        return z;
    }
};

// Клас Logger
class Logger {
public:
    static void log(const std::string& message) {
        std::cout << "Log: " << message << std::endl;
    }
};

// Функція для визначення, чи є вектори колінеарними або ортогональними
void checkCollinearityAndOrthogonality(const Vector& v1, const Vector& v2) {
    double dotProduct = v1.dotProduct(v2);

    if (std::abs(dotProduct) == v1.getMagnitude() * v2.getMagnitude()) {
        Logger::log("Vectors are collinear.");
    }
    else if (dotProduct == 0) {
        Logger::log("Vectors are orthogonal.");
    }
    else {
        Logger::log("Vectors are neither collinear nor orthogonal.");
    }
}

int main() {
    // Оголошення вектора об'єктів Vector
    std::vector<Vector> vectors = {
        Vector(1, 2, 3),
        Vector(4, 5, 6),
        Vector(7, 8, 9)
    };

    // Використання методів класу Vector
    for (size_t i = 0; i < vectors.size(); i++) {
        double magnitude = vectors[i].getMagnitude();
        Logger::log("Magnitude of vector " + std::to_string(i + 1) + ": " + std::to_string(magnitude));
    }

    Vector sum = vectors[0].add(vectors[1]);
    Logger::log("Sum of the first and second vectors: (" + std::to_string(sum.getX()) + ", " +
        std::to_string(sum.getY()) + ", " + std::to_string(sum.getZ()) + ")");

    Vector difference = vectors[0].subtract(vectors[2]);
    Logger::log("Difference between the first and third vectors: (" + std::to_string(difference.getX()) + ", " +
        std::to_string(difference.getY()) + ", " + std::to_string(difference.getZ()) + ")");

    Vector multiplied = vectors[0].multiply(2.5);
    Logger::log("Multiplication of the first vector by 2.5: (" + std::to_string(multiplied.getX()) + ", " +
        std::to_string(multiplied.getY()) + ", " + std::to_string(multiplied.getZ()) + ")");

    // Виклик методу для перевірки колінеарності та ортогональності
    checkCollinearityAndOrthogonality(vectors[0], vectors[1]);

    return 0;
}
