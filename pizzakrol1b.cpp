#include <iostream>
#include <string>

// Produkt - klasa reprezentująca pizzę
class Pizza {
public:
    void setDough(const std::string& dough) {
        this->dough = dough;
    }

    void setSauce(const std::string& sauce) {
        this->sauce = sauce;
    }

    void setTopping(const std::string& topping) {
        this->topping = topping;
    }

    void displayPizza() const {
        std::cout << "Pizza with Dough: " << dough
                  << ", Sauce: " << sauce
                  << ", Topping: " << topping << std::endl;
    }

private:
    std::string dough;
    std::string sauce;
    std::string topping;
};

// Interfejs budowniczego
class PizzaBuilder {
public:
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
    virtual Pizza getPizza() const = 0;
};

// Konkretny budowniczy dla konkretnego typu pizzy (Hawajska)
class HawaiianPizzaBuilder : public PizzaBuilder {
public:
    void buildDough() override {
        pizza.setDough("Pan Dough");
    }

    void buildSauce() override {
        pizza.setSauce("Hawaiian Sauce");
    }

    void buildTopping() override {
        pizza.setTopping("Ham and Pineapple");
    }

    Pizza getPizza() const override {
        return pizza;
    }

private:
    Pizza pizza;
};

// Konkretny budowniczy dla innego typu pizzy (Pikantna)
class SpicyPizzaBuilder : public PizzaBuilder {
public:
    void buildDough() override {
        pizza.setDough("Thin Dough");
    }

    void buildSauce() override {
        pizza.setSauce("Spicy Tomato Sauce");
    }

    void buildTopping() override {
        pizza.setTopping("Pepperoni and Jalapenos");
    }

    Pizza getPizza() const override {
        return pizza;
    }

private:
    Pizza pizza;
};

// Nowy konkretny budowniczy dla dodatkowego typu pizzy (Król)
class KrolPizzaBuilder : public PizzaBuilder {
public:
    void buildDough() override {
        pizza.setDough("Thick Dough");
    }

    void buildSauce() override {
        pizza.setSauce("Royal Tomato Sauce");
    }

    void buildTopping() override {
        pizza.setTopping("Gold and Caviar");
    }

    Pizza getPizza() const override {
        return pizza;
    }

private:
    Pizza pizza;
};

// Kierownik - klasa, która orchestratuje budowę
class Cook {
public:
    void makePizza(PizzaBuilder& builder) {
        builder.buildDough();
        builder.buildSauce();
        builder.buildTopping();
    }
};

// Funkcja main
int main() {
    Cook cook;

    // Budowniczy dla pizzy hawajskiej
    HawaiianPizzaBuilder hawaiianBuilder;
    cook.makePizza(hawaiianBuilder);
    Pizza hawaiianPizza = hawaiianBuilder.getPizza();
    std::cout << "Hawaiian Pizza Configuration:" << std::endl;
    hawaiianPizza.displayPizza();

    // Budowniczy dla pikantnej pizzy
    SpicyPizzaBuilder spicyBuilder;
    cook.makePizza(spicyBuilder);
    Pizza spicyPizza = spicyBuilder.getPizza();
    std::cout << "\nSpicy Pizza Configuration:" << std::endl;
    spicyPizza.displayPizza();

    // Nowy budowniczy dla pizzy Król
    KrolPizzaBuilder krolBuilder;
    cook.makePizza(krolBuilder);
    Pizza krolPizza = krolBuilder.getPizza();
    std::cout << "\nKról Pizza Configuration:" << std::endl;
    krolPizza.displayPizza();

    return 0;
}
