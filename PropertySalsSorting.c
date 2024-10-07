#include <stdio.h>
#include <string.h>

#define N 100

// proparty sale structure
struct PropertySale {
    int UID;
    char address[100];
    int  ZIP;
    int size;
    int year;
    double price;
};

//  database of sale
struct SalesDatabase {
    struct PropertySale sales[100];
    int count; // we will count by this
};


struct SalesDatabase Sale(struct SalesDatabase db, int uid, const char* address, int zip, int size, int year, double price) {

        db.sales[db.count].UID = uid;
        strcpy(db.sales[db.count].address, address);
        db.sales[db.count].ZIP =zip;
        db.sales[db.count].size = size;
        db.sales[db.count].year = year;
        db.sales[db.count].price = price;
        db.count++;


        return db;
}

// print function
void PrintSales(struct SalesDatabase db) {

        for (int i = 0; i < db.count; i++) {
            printf("UID: %d, Address: %s, ZIP: %d, Size: %d sqft, Year: %d, Price: %.2f Lak\n",
                   db.sales[i].UID, db.sales[i].address, db.sales[i].ZIP,
                   db.sales[i].size, db.sales[i].year, db.sales[i].price);
        }

}




// ascending order sort
struct SalesDatabase SortByPriceAsc(struct SalesDatabase db) {
    for (int i = 0; i < db.count - 1; i++) {
        for (int j = 0; j < db.count-1-i; j++) {
            if (db.sales[j].price > db.sales[j+1].price) {
                // Swap
                struct PropertySale temp = db.sales[j];
                db.sales[j] = db.sales[j+1];
                db.sales[j+1] = temp;
            }
        }
    }
    printf("Ascending sorted.\n");
    return db;
}

// sorted by Descending order
struct SalesDatabase SortByPriceDesc(struct SalesDatabase db) {
    for (int i = 0; i < db.count - 1; i++) {
        for (int j = 0; j < db.count-1-i; j++) {
            if (db.sales[j].price < db.sales[j+1].price) {
                // Swap
                struct PropertySale temp = db.sales[j];
                db.sales[j] = db.sales[j+1];
                db.sales[j+1] = temp;
            }
        }
    }
    printf("Descending sorted.\n");
    return db;
}



void SortRangPrice(struct SalesDatabase db, double lb, double ub) {

    for (int i = 0; i < db.count - 1; i++) {
        for (int j = 0; j < db.count - 1 - i; j++) {
            if (db.sales[j].price > db.sales[j + 1].price) {
                //swap
                struct PropertySale temp = db.sales[j];
                db.sales[j] = db.sales[j + 1];
                db.sales[j + 1] = temp;
            }
        }
    }


    printf("Price Range %.2f to %.2f:\n", lb, ub);
    for (int i = 0; i < db.count; i++) {
        if (db.sales[i].price >= lb && db.sales[i].price <= ub) {
            printf("UID: %d, Address: %s, ZIP: %d, Size: %d sqft, Year: %d, Price: %.2f Lak\n",
                   db.sales[i].UID, db.sales[i].address, db.sales[i].ZIP,
                   db.sales[i].size, db.sales[i].year, db.sales[i].price);
        }
    }
}
// sort rang by UID
void SortRangUID(struct SalesDatabase db, int lb, int ub) {

    for (int i = 0; i < db.count - 1; i++) {
        for (int j = 0; j < db.count - 1 - i; j++) {
            if (db.sales[j].UID > db.sales[j + 1].UID) {
               //swip
                struct PropertySale temp = db.sales[j];
                db.sales[j] = db.sales[j + 1];
                db.sales[j + 1] = temp;
            }
        }
    }


    printf("UID Range %d to %d:\n", lb, ub);
    for (int i = 0; i < db.count; i++) {
        if (db.sales[i].UID >= lb && db.sales[i].UID <= ub) {
            printf("UID: %d, Address: %s, ZIP: %d, Size: %d sqft, Year: %d, Price: %.2f Lak\n",
                   db.sales[i].UID, db.sales[i].address, db.sales[i].ZIP,
                   db.sales[i].size, db.sales[i].year, db.sales[i].price);
        }
    }
}
void SortRangeFlatSize(struct SalesDatabase db, int lb, int ub) {

    for (int i = 0; i < db.count - 1; i++) {
        for (int j = 0; j < db.count - 1 - i; j++) {
            if (db.sales[j].size > db.sales[j + 1].size) {
                // swap
                struct PropertySale temp = db.sales[j];
                db.sales[j] = db.sales[j + 1];
                db.sales[j + 1] = temp;
            }
        }
    }


    printf("Size Range %d to %d:\n", lb, ub);
    for (int i = 0; i < db.count; i++) {
        if (db.sales[i].size >= lb && db.sales[i].size <= ub) {
            printf("UID: %d, Address: %s, ZIP: %d, Size: %d sqft, Year: %d, Price: %.2f Lak\n",
                   db.sales[i].UID, db.sales[i].address, db.sales[i].ZIP,
                   db.sales[i].size, db.sales[i].year, db.sales[i].price);
        }
    }
}

int main() {
    struct SalesDatabase db;
    db.count = 0;


    db = Sale(db, 106, "Mirpur,       Dhaka", 1208, 1500, 2010, 25.0);
    db = Sale(db, 102, "Kanchon,  Naraygong", 1202, 2015, 2023,20.0);
    db = Sale(db, 103, "sripur,     Gazipur", 1608, 1800, 2020, 30.0);
    db = Sale(db, 104, "Hemayetpur,  pabna",  6602, 1400, 2019, 12.0);
    db = Sale(db, 105, "Kustiya       Sador", 1708, 2200, 2017, 58.0);
    db = Sale(db, 101, "Tebari,       Nator", 1908, 850, 2024, 35.0);
    db = Sale(db, 107, "Birol,     Dinajpur", 4508, 1760, 2014, 45.0);
    db = Sale(db, 108, "Lokkipur,   Rajsahi", 1245, 900, 2015, 10.0);
    db = Sale(db, 109, "Rupsha,      Khulna", 2004, 1145, 2021, 18.0);
    db = Sale(db, 110, "Teknaf,    Coxbazar", 1518, 2280, 2016, 40.0);

    PrintSales(db);

    db = SortByPriceAsc(db); // Assending order sort
    PrintSales(db);
    db = SortByPriceDesc(db);  // Deasending order sort
    PrintSales(db);
    SortRangPrice(db,10.0, 25.0); // 10 Lak to 25 lak
    SortRangUID(db,102, 104); // UID 102 to 104
    SortRangeFlatSize(db,800, 1200); // flat Size 800 to 1200;

    return 0;
}

