// TCSS 483 Winter
// Zachary Anderson

#include <stdio.h>
#include <regex.h>
#include <stdbool.h>

// Got a basic setup for method that checks valid numbers with regex in C from chatGPT and modified for my use


// Function to check if a string is a valid social security number
bool social_security_number(const char *str) {
    regex_t regex;
    int reti;

    // Regular expression pattern for a valid social security number
    // "^([0-9]{9}|[0-9]{3}\\-[0-9]{2}\\-[0-9]{4}|[0-9]{3}\\s[0-9]{2}\\s[0-9]{4})$"
    // [0-9]{9}             -> Allows for nine random numbers
    // [0-9]{3}\\-[0-9]{2}\\-[0-9]{4}   -> Allows for three random numbers with - two random numbers with - four random numbers
    // [0-9]{3}\\s[0-9]{2}\\s[0-9]{4}   -> Allows for three random numbers with space two random numbers with space four random numbers
    const char *pattern = "^([0-9]{9}|[0-9]{3}\\-[0-9]{2}\\-[0-9]{4}|[0-9]{3}\\s[0-9]{2}\\s[0-9]{4})$";

    // Compile the regex
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        printf("Could not compile regex\n");
        return false;
    }

    // Execute regex
    reti = regexec(&regex, str, 0, NULL, 0);
    regfree(&regex); // Free memory allocated for regex

    return reti == 0; // If 0, it matches; otherwise, it doesn't
}



// Function to check if a string is a valid phone number
bool phone_number(const char *str) {
    regex_t regex;
    int reti;

    // Regular expression pattern for a valid phone number
    // "^([0-9]{10}|\\([0-9]{3}\\)[0-9]{3}\\-[0-9]{4})$"
    // [0-9]{10}            -> Allows for ten random numbers
    // \\([0-9]{3}\\)[0-9]{3}\\-[0-9]{4}    -> Has to have ( and three random numbers has to have ) and three random numbers has to have - and four random numbers
    const char *pattern = "^([0-9]{10}|\\([0-9]{3}\\)[0-9]{3}\\-[0-9]{4})$";

    // Compile the regex
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        printf("Could not compile regex\n");
        return false;
    }

    // Execute regex
    reti = regexec(&regex, str, 0, NULL, 0);
    regfree(&regex); // Free memory allocated for regex

    return reti == 0; // If 0, it matches; otherwise, it doesn't
}


// No numbers allowed after the @ symbol
// Function to check if a string is a valid email address
bool email_address(const char *str) {
    regex_t regex;
    int reti;

    // Regular expression pattern for a valid email address
    // "^[a-zA-Z0-9]+\\@[a-z]*\\.[a-z]*$"
    // ^[a-zA-z0-9]+    -> Allows for atleast one lowercase letters, uppercase letters and numbers
    // \\@              -> Has to have @
    // [a-z]+           -> Has to have atleast one lowercase letter
    // \\.              -> Has to have .
    // [a-z]+$          -> Has to have atleast one lowercase letter
    const char *pattern = "^[a-zA-Z0-9]+\\@[a-z]+\\.[a-z]+$";

    // Compile the regex
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        printf("Could not compile regex\n");
        return false;
    }

    // Execute regex
    reti = regexec(&regex, str, 0, NULL, 0);
    regfree(&regex); // Free memory allocated for regex

    return reti == 0; // If 0, it matches; otherwise, it doesn't
}


// Allows zero middle initials up to two middle initials
// Function to check if a string is a valid class roster name
bool class_roster_name(const char *str) {
    regex_t regex;
    int reti;

    // Regular expression pattern for a valid class roster name
    // "^[A-Z]{1}[a-z]+\\,\\s[A-Z]{1}[a-z]+\\,?\\s?[A-Z]*\\,?\\s?[A-Z]*$"
    // ^[A-Z]{1}        -> Allow any random one uppercase letter
    // [a-z]+           -> Has to have atleast one lowercase letter
    // \\,              -> Has to have ,
    // \\s              -> Has to have space
    // [A-Z]{1}         -> Allow any random one uppercase letter
    // [a-z]+           -> Has to have atleast one lowercase letter
    // \\,?             -> Optional ,
    // \\s?             -> Optional space
    // ([A-Z]{1}|[A-Z]{1}\\,\\s[A-Z])?  -> Optional to have one uppercase letter or two uppercase letters seperated by , and space 
    const char *pattern = "^[A-Z]{1}[a-z]+\\,\\s[A-Z]{1}[a-z]+\\,?\\s?([A-Z]{1}|[A-Z]{1}\\,\\s[A-Z])?$";

    // Compile the regex
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        printf("Could not compile regex\n");
        return false;
    }

    // Execute regex
    reti = regexec(&regex, str, 0, NULL, 0);
    regfree(&regex); // Free memory allocated for regex

    return reti == 0; // If 0, it matches; otherwise, it doesn't
}


// Allows for years between 1900 and 2099 and did not figure out leap year or exact days to month
// Function to check if a string is a valid date month day year
bool date_month_day_year(const char *str) {
    regex_t regex;
    int reti;

    // Regular expression pattern for a valid date month day year
    // "^(0[1-9]|1[0-2])\\-(0[1-9]|[12][0-9]|3[01])\\-((19|20)[0-9]{2})$"
    // ^(0[1-9]|1[0-2]) -> Allows for 0 with 1-9 or 1 with 0-2
    // \\-              -> Has to have -
    // (0[1-9]|[12][0-9]|3[01]) -> Allows for 0 with 1-9 or 1 and 2 with 0-9 or 3 with 0 and 1
    // \\-              -> Has to have -
    // ((19|20)[0-9]{2})    -> Allows for 19 or 20 with any two numbers
    const char *pattern = "^(0[1-9]|1[0-2])\\-(0[1-9]|[12][0-9]|3[01])\\-((19|20)[0-9]{2})$";

    // Compile the regex
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        printf("Could not compile regex\n");
        return false;
    }

    // Execute regex
    reti = regexec(&regex, str, 0, NULL, 0);
    regfree(&regex); // Free memory allocated for regex

    return reti == 0; // If 0, it matches; otherwise, it doesn't
}



// Function to check if a string is a valid house address
bool house_address(const char *str) {
    regex_t regex;
    int reti;

    // Regular expression pattern for a valid house address
    // "^[0-9]+\\s[0-9]*[A-Z]{1}?[a-z]+\\s[RSBA]+[a-z]+$"
    // ^[0-9]+          -> Has to have atleast one number
    // \\s              -> Has to have space
    // [0-9]*           -> Allows for any number of numbers
    // [A_Z]{1}?        -> Optional one uppercase letter
    // [a-z]+?          -> Optional atleast one lowercase letter
    // \\s              -> Has to have space
    // (Rd|Road|St|Street|Blvd|Boulevard|Ave|Avenue)    -> Can be Rd or Road or St or Street or Blvd or Boulevard or Ave or Avenue
    const char *pattern = "^[0-9]+\\s[0-9]*[A-Z]{1}?[a-z]+?\\s(Rd|Road|St|Street|Blvd|Boulevard|Ave|Avenue)$";

    // Compile the regex
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        printf("Could not compile regex\n");
        return false;
    }

    // Execute regex
    reti = regexec(&regex, str, 0, NULL, 0);
    regfree(&regex); // Free memory allocated for regex

    return reti == 0; // If 0, it matches; otherwise, it doesn't
}


// Allows for two named cities at most
// Function to check if a string is a valid city state zip
bool city_state_zip(const char *str) {
    regex_t regex;
    int reti;

    // Regular expression pattern for a valid city state zip
    // "^[A-Z]{1}[a-z]+\\s?[A-Z]{1}?[a-z]+?\\,\\s[A-Z]{1}[a-z]+\\,\\s[0-9]{5}$"
    // ^[A_Z]{1}        -> Has to have one uppercase letter
    // [a-z]+           -> Has to have atleast one lowercase letter
    // \\s?             -> Optional space
    // [A_Z]{1}?        -> Optional one uppercase letter
    // [a-z]+?          -> Optional atleast one lowercase letter
    // \\,              -> Has to have ,
    // \\s              -> Has to have space
    // [A_Z]{1}         -> Has to have one uppercase letter
    // [a-z]+           -> Has to have atleast one lowercase letter
    // \\,              -> Has to have ,
    // \\s              -> Has to have space
    // [0-9]{5}$        -> Has to have five random numbers
    const char *pattern = "^[A-Z]{1}[a-z]+\\s?[A-Z]{1}?[a-z]+?\\,\\s[A-Z]{1}[a-z]+\\,\\s[0-9]{5}$";

    // Compile the regex
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        printf("Could not compile regex\n");
        return false;
    }

    // Execute regex
    reti = regexec(&regex, str, 0, NULL, 0);
    regfree(&regex); // Free memory allocated for regex

    return reti == 0; // If 0, it matches; otherwise, it doesn't
}


// Midnight is represented as 0000 not 2400
// Function to check if a string is a valid military time
bool military_time(const char *str) {
    regex_t regex;
    int reti;

    // Regular expression pattern for a valid military time
    // "^(0[0-2]{1}|1[0-9]{1}|2[0-3]{1})[0-5]{1}[0-9]{1}$"
    // ^(0[0-2]{1}|1[0-9]{1}|2[0-3]{1}) -> Can be 0 with one number from 0-2 or 1 with one number from 0-9 or 2 with one number 0-3
    // [0-5]{1}         -> Has to have one number from 0-5
    // [0-9]{1}$        -> Has to have one random number
    const char *pattern = "^(0[0-2]{1}|1[0-9]{1}|2[0-3]{1})[0-5]{1}[0-9]{1}$";

    // Compile the regex
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        printf("Could not compile regex\n");
        return false;
    }

    // Execute regex
    reti = regexec(&regex, str, 0, NULL, 0);
    regfree(&regex); // Free memory allocated for regex

    return reti == 0; // If 0, it matches; otherwise, it doesn't
}



// Function to check if a string is a valid US currenncy
bool us_currency(const char *str) {
    regex_t regex;
    int reti;

    // Regular expression pattern for a valid US currency
    // "^\\$[0-9]*\\,?[0-9]*\\.[0-9]{2}$"
    // ^\\$             -> Has to have $
    // [0-9]*           -> Allows for any number of numbers
    // \\,?             -> Optional ,
    // [0-9]*           -> Allows for any number of numbers
    // \\.              -> Has to have .
    // [0-9]{2}         -> Has to have two random number
    const char *pattern = "^\\$[0-9]*\\,?[0-9]*\\.[0-9]{2}$";

    // Compile the regex
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        printf("Could not compile regex\n");
        return false;
    }

    // Execute regex
    reti = regexec(&regex, str, 0, NULL, 0);
    regfree(&regex); // Free memory allocated for regex

    return reti == 0; // If 0, it matches; otherwise, it doesn't
}


// Only allows .com, .COM, .org, .ORG and can't have any numbers in the website
// Function to check if a string is a valid URL
bool url(const char *str) {
    regex_t regex;
    int reti;

    // Regular expression pattern for a valid URL
    // "^(http://|HTTP://|https://|HTTPS://)[a-zA-Z]+(.com|.COM|.org|.ORG)$"
    // ^(http://|HTTP://|https://|HTTPS://)     -> Can be http:// or HTTP:// or https:// or HTTPS://
    // [a-zA-Z]+            -> Has to be atleast one lowercase or uppercase letter
    // (.com|.COM|.org|.ORG)$   -> Can be .com or .COM or .org or .ORG
    const char *pattern = "^(http://|HTTP://|https://|HTTPS://)[a-zA-Z]+(.com|.COM|.org|.ORG)$";

    // Compile the regex
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        printf("Could not compile regex\n");
        return false;
    }

    // Execute regex
    reti = regexec(&regex, str, 0, NULL, 0);
    regfree(&regex); // Free memory allocated for regex

    return reti == 0; // If 0, it matches; otherwise, it doesn't
}


// This one is a mess, I ultimately could not figure out how to get everything to go in random with C
// Just forced 10 total of all the options
// Function to check if a string is a valid password
bool password(const char *str) {
    regex_t regex;
    int reti;

    // Regular expression pattern for a valid password
    // "^[A-Za-z0-9[:punct:]]{10}$"
    // [A-Za-z0-9[:punct:]]{10}     -> Has to have ten uppercase letter, lowercase letter, random number, and puntuation mark
    const char *pattern = "^[A-Za-z0-9[:punct:]]{10}$";

    // Was going to do an or statement with all possibilites, but the number was way to high for possibilities
    // Just had way to much trouble with this one, I don't know why I couldn't get them to input randomly, just wanted to be in order
    // const char *pattern = "^[A-Z]+[a-z]{3}[0-9]+[a-z]{3}[[:punct:]]+[a-z]{3}$";

    // Compile the regex
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        printf("Could not compile regex\n");
        return false;
    }

    // Execute regex
    reti = regexec(&regex, str, 0, NULL, 0);
    regfree(&regex); // Free memory allocated for regex

    return reti == 0; // If 0, it matches; otherwise, it doesn't
}


// Goes up to words up to 9 letters long for odd words
// Function to check if a string is a valid odd number word ending with ion
bool odd_number_words_ion(const char *str) {
    regex_t regex;
    int reti;

    // Regular expression pattern for a valid odd number word ending with ion
    // "^(ion|[a-zA-Z]{2}ion|[a-zA-Z]{4}ion|[a-zA-Z]{6}ion)$"
    // ion              -> Has to have ion
    // [a-zA-Z]{2}ion   -> Has to have two lowercase or uppercase letter and ion
    // [a-zA-Z]{4}ion   -> Has to have four lowercase or uppercase letter and ion
    // [a-zA-Z]{6}ion   -> Has to have six lowercase or uppercase letter and ion
    const char *pattern = "^(ion|[a-zA-Z]{2}ion|[a-zA-Z]{4}ion|[a-zA-Z]{6}ion)$";

    // Compile the regex
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        printf("Could not compile regex\n");
        return false;
    }

    // Execute regex
    reti = regexec(&regex, str, 0, NULL, 0);
    regfree(&regex); // Free memory allocated for regex

    return reti == 0; // If 0, it matches; otherwise, it doesn't
}



int main() {
//----------------------------------------------------------------------------------------------------------------------------------------------
    // Tests for social_security_number
    const char *test_cases[] = {
        "123456789", "123-45-6789", "123 45 6789", "111111111", "111-11-1111", "111 11 1111", "000000000", "999999999",
        "123-45-67891", "1111-11-111", "757 575757", "123 45-6789", "11111-1111", "75-757 5757", "00000 0000", "111-111111",
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    for (int i = 0; i < num_tests; i++) {
        printf("Testing: social_security_number \"%s\": %s\n", test_cases[i], social_security_number(test_cases[i]) ? "Valid" : "Invalid");
    }

//----------------------------------------------------------------------------------------------------------------------------------------------
    // Tests for phone_number
    const char *test_cases_1[] = {
        "0123456789", "(012)345-6789", "0000000000", "(000)000-0000", "9999999999", "(999)999-9999", "1111111111", "(111)111-1111",
        "012345-6789", "(000)0000000", "01234567891", "123456789", "(0000000000", "777)7777777", "(555555-5555", "444)444-4444",
    };

    int num_tests_1 = sizeof(test_cases_1) / sizeof(test_cases_1[0]);
    for (int i = 0; i < num_tests_1; i++) {
        printf("Testing: phone_number \"%s\": %s\n", test_cases_1[i], phone_number(test_cases_1[i]) ? "Valid" : "Invalid");
    }

//----------------------------------------------------------------------------------------------------------------------------------------------
    // Tests for email_address
    const char *test_cases_2[] = {
        "dog@gmail.com", "DOG@outlook.com", "dog123@uw.edu", "123dog@yahoo.com", "d102g3@hotmail.com", "123@spscc.edu", "a0@a.a", "abcdefghijklmnopqrstuvwxyz0123456789@google.com",
        "dog@GMAIL.COM", "123@.", "@google.com", "sam21@0utl00k.com", "dude@yahoo.c0m", "doodlebobyahoo.com", "patrick@hotmailcom", "go@GMAIL.com",
    };

    int num_tests_2 = sizeof(test_cases_2) / sizeof(test_cases_2[0]);
    for (int i = 0; i < num_tests_2; i++) {
        printf("Testing: email_address \"%s\": %s\n", test_cases_2[i], email_address(test_cases_2[i]) ? "Valid" : "Invalid");
    }

//----------------------------------------------------------------------------------------------------------------------------------------------
    // Tests for class_roster_name
    const char *test_cases_3[] = {
        "Doe, John", "An, De, B", "Smith, Daniel, H, O", "Az, Za, Z, A", "Za, Az, A, Z", "Az, Za,", "Za, Az,", "Az, Za, A",
        "123-45-67891", "aN, dE, b", "A, Z, C", "case, lower", "Destiny, Rain, DD, AA", "Merry, Chris, SS", "Samuel Tim G", "song, jim,",
    };

    int num_tests_3 = sizeof(test_cases_3) / sizeof(test_cases_3[0]);
    for (int i = 0; i < num_tests_3; i++) {
        printf("Testing: class_roster_name \"%s\": %s\n", test_cases_3[i], class_roster_name(test_cases_3[i]) ? "Valid" : "Invalid");
    }

//----------------------------------------------------------------------------------------------------------------------------------------------
    // Tests for date_month_day_year
    const char *test_cases_4[] = {
        "01-01-2000", "12-25-2024", "07-12-2099", "02-28-1900", "03-31-2025", "04-01-1901", "11-11-2011", "07-21-1989",
        "11-05-2100", "02-28-1899", "00-01-2000", "01-00-2000", "13-13-2021", "12-32-1901", "00-00-0000", "11-11-1111",
    };

    int num_tests_4 = sizeof(test_cases_4) / sizeof(test_cases_4[0]);
    for (int i = 0; i < num_tests_4; i++) {
        printf("Testing: date_month_day_year \"%s\": %s\n", test_cases_4[i], date_month_day_year(test_cases_4[i]) ? "Valid" : "Invalid");
    }

//----------------------------------------------------------------------------------------------------------------------------------------------
    // Tests for house_address
    const char *test_cases_5[] = {
        "13 Spooky Rd", "13 Spooky Road", "100 35th St", "0 F Boulevard", "0 F Blvd", "100 35th Street", "2100 Barry Ave", "2100 Barry Avenue", 
        "100 35th st", "101 36th rd", "102 37th blvd", "103 38th ave", "104 39th street", "105 40th road", "106 41th boulevard", "107 42th avenue", 
    };

    int num_tests_5 = sizeof(test_cases_5) / sizeof(test_cases_5[0]);
    for (int i = 0; i < num_tests_5; i++) {
        printf("Testing: house_address \"%s\": %s\n", test_cases_5[i], house_address(test_cases_5[i]) ? "Valid" : "Invalid");
    }

//----------------------------------------------------------------------------------------------------------------------------------------------
    // Tests for city_state_zip
    const char *test_cases_6[] = {
        "Olympia, Washington, 98513", "San Antonio, Texas, 78015", "Za, Za, 00000", "Az, Az, 99999", "Aa, Aa, 00000", "Zz, Zz, 99999", "Za Za, Za, 00000", "Az Az, Az, 99999",
        "aa, Aa, 11111", "Az, az, 11111", "Az, Az, 1111", "Az, Az, 111111", "Az AzA, Az, 11111", "AA, Aa, 11111", "Aa, AA, 11111", "Aa AA, Aa, 11111",
    };

    int num_tests_6 = sizeof(test_cases_6) / sizeof(test_cases_6[0]);
    for (int i = 0; i < num_tests_6; i++) {
        printf("Testing: city_state_zip \"%s\": %s\n", test_cases_6[i], city_state_zip(test_cases_6[i]) ? "Valid" : "Invalid");
    }

//----------------------------------------------------------------------------------------------------------------------------------------------
    // Tests for military_time
    const char *test_cases_7[] = {
        "0001", "2359", "1959", "2050", "0000", "0100", "2300", "1111",
        "2400", "2401", "2360", "3000", "2500", "100", "10", "1",
    };

    int num_tests_7 = sizeof(test_cases_7) / sizeof(test_cases_7[0]);
    for (int i = 0; i < num_tests_7; i++) {
        printf("Testing: military_time \"%s\": %s\n", test_cases_7[i], military_time(test_cases_7[i]) ? "Valid" : "Invalid");
    }

//----------------------------------------------------------------------------------------------------------------------------------------------
    // Tests for us_currency
    const char *test_cases_8[] = {
        "$0.10", "$23.59", "$1,959.00", "$205,010.59", "$0.00", "$999,999.99", "$123,456.78", "$876,543.21",
        "$0.0", "$9", "$9,999", "123,456.78", "$1,000,000.00", "-$0.00", "00", "0",
    };

    int num_tests_8 = sizeof(test_cases_8) / sizeof(test_cases_8[0]);
    for (int i = 0; i < num_tests_8; i++) {
        printf("Testing: us_currency \"%s\": %s\n", test_cases_8[i], us_currency(test_cases_8[i]) ? "Valid" : "Invalid");
    }

//----------------------------------------------------------------------------------------------------------------------------------------------
    // Tests for url
    const char *test_cases_9[] = {
        "http://google.com", "HTTP://GOOGLE.COM", "https://google.com", "HTTPS://GOOGLE.COM", "http://wsecu.org", "HTTP://WSECU.ORG", "http://a.com", "https://a.org",
        "htp://google.com", "HTP://GOOGLE.COM", "htps://google.com", "HTPS://GOOGLE.COM", "htp://wsecu.org", "HTP://WSECU.ORG", "htps:wsecu.org", "HTPS://WSECU.ORG",
    };

    int num_tests_9 = sizeof(test_cases_9) / sizeof(test_cases_9[0]);
    for (int i = 0; i < num_tests_9; i++) {
        printf("Testing: url \"%s\": %s\n", test_cases_9[i], url(test_cases_9[i]) ? "Valid" : "Invalid");
    }

//----------------------------------------------------------------------------------------------------------------------------------------------
    // Tests for password
    const char *test_cases_10[] = {
        "Com9put!er", "Com!put9er", "Co9mpu!ter", "Co!mpu9ter", "aZ09!@#$^&", "AAAzzz000*", "000999Za&*", "NotGood!10",
        "123-45-67891", "1", "!", "Z", "a", "oof", "____________", "ZZZZZZZZZZZ",
    };

    int num_tests_10 = sizeof(test_cases_10) / sizeof(test_cases_10[0]);
    for (int i = 0; i < num_tests_10; i++) {
        printf("Testing: password \"%s\": %s\n", test_cases_10[i], password(test_cases_10[i]) ? "Valid" : "Invalid");
    }

//----------------------------------------------------------------------------------------------------------------------------------------------
    // Tests for odd_number_words_ion
    const char *test_cases_11[] = {
        "ion", "onion", "Onion", "bastion", "assertion", "Azion", "Zaion", "Zazaion",
        "transitioned", "Ion", "ION", "lion", "12ion", "balion", "i", "io",
    };

    int num_tests_11 = sizeof(test_cases_11) / sizeof(test_cases_11[0]);
    for (int i = 0; i < num_tests_11; i++) {
        printf("Testing: odd_number_words_ion \"%s\": %s\n", test_cases_11[i], odd_number_words_ion(test_cases_11[i]) ? "Valid" : "Invalid");
    }

    return 0;
}