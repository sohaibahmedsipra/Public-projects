import csv

game_numbers = []
dates = []
hours = []
categories = []
countries = []
goals_for = []
goals_against = []
yellow_cards = []
red_cards = []
possession_percent = []
attempts = []
fouls = []
offsides = []
passes_attempted = []
passes_completed = []
corner_kicks = []
goals_prevented = []


with open('worldcupdata_4.csv', 'r') as csvfile:
    reader = csv.reader(csvfile)
    next(reader)
    for row in reader:
        game_numbers.append(row[0])
        dates.append(row[1])
        hours.append(row[2])
        categories.append(row[3])
        countries.append(row[4])
        goals_for.append(row[5])
        goals_against.append(row[6])
        yellow_cards.append(row[7])
        red_cards.append(row[8])
        possession_percent.append(row[9])
        attempts.append(row[10])
        fouls.append(row[11])
        offsides.append(row[12])
        passes_attempted.append(row[13])
        passes_completed.append(row[14])
        corner_kicks.append(row[15])
        goals_prevented.append(row[16])


def max_value_teams(statistic, countries, values):
    max_value = max(values)
    max_indices = [i for i, x in enumerate(values) if x == max_value]
    print(f"The team(s) with the maximum {statistic} is/are:")
    for index in max_indices:
        print(f"{countries[index]}: {values[index]}")


def min_value_teams(statistic, countries, values):
    min_value = min(values)
    min_indices = [i for i, x in enumerate(values) if x == min_value]
    print(f"The team(s) with the minimum {statistic} is/are:")
    for index in min_indices:
        print(f"{countries[index]}: {values[index]}")

def above_average_teams(statistic, countries, values):
    values_int = []
    for value in values:
        value_int = int(value)
        values_int.append(value_int)

    avg_value = sum(values_int) / len(values)

    above_avg_indices = [i for i, x in enumerate(values_int) if x > avg_value]

    print(f"The team(s) with a {statistic} greater than the average ({avg_value:.2f}) is/are:")
    for index in above_avg_indices:
        print(f"{countries[index]}: {values_int[index]}")

def below_avg_teams(statistic, countries, values):

    values_int = []
    for value in values:
        value_int = int(value)
        values_int.append(value_int)


    avg_value = sum(values_int) / len(values)

    below_avg_indices = [i for i, x in enumerate(values_int) if x < avg_value]

    print(f"The team(s) with a {statistic} less than the average ({avg_value:.2f}) is/are:")
    for index in below_avg_indices:
        print(f"{countries[index]}: {values_int[index]}")


def print_all():
    header = ('game#     date       hour      category    team1               team2                 score')
    print(header, "\n")

    with open('worldcupdata_4.csv', 'r') as file:
        csv_reader = csv.reader(file)
        next(csv_reader)

        for i, line in enumerate(csv_reader):
            if i % 2 == 0:
                team1 = line[4]
                team2 = ''
                scorefor = ''
                game_num = line[0]
                date = line[1]
                hour = line[2]
                category = line[3]
                goals_against = line[5]
            else:
                team2 = line[4]
                scorefor = line[5]
                print(f'{game_num:<6}  {date:<11} {hour:<9} {category:<11} {team1:<20} {team2:<20} {goals_against}-{scorefor}')



def print_menu():
    print("WORLD CUP SOCCER ANALYSIS PROGRAM")
    print("--------------------------------------------------------------")
    print("(1) Print Group Play Game Summary")
    print("(2) Report Teams(s) having maximum value for requested statistic")
    print("(3) Report Teams(s) having minimum value for requested statistic")
    print("(4) Report Teams(s) having value greater than average for requested statistic")
    print("(5) Report Teams(s) having value less than average for requested statistic")
    print("(9) End program")
    print("--------------------------------------------------------------")


def f_get_menu_option():
    men = True;
    while men:
        print_menu()
        choice = input("Enter a number to choose a command: ")
        if choice == "1":
            print_all();
            pass
        elif choice == "2":
            print("Which statistic would you like to use?")
            print("(1) Goals For")
            print("(2) Goals Against")
            print("(3) Yellow Cards")
            print("(4) Red Cards")
            print("(5) Possession Percentage")
            print("(6) Attempts")
            print("(7) Fouls")
            print("(8) Offsides")
            print("(9) Passes Attempted")
            print("(10) Passes Completed")
            print("(11) Corner Kicks")
            print("(12) Goals Prevented")

            choice = input("Enter a number to choose a statistic: ")
            if choice == "1":
                statistic = "goals_for"
            elif choice == "2":
                statistic = "goals_against"
            elif choice == "3":
                statistic = "yellow_cards"
            elif choice == "4":
                statistic = "red_cards"
            elif choice == "5":
                statistic = "possession_percent"
            elif choice == "6":
                statistic = "attempts"
            elif choice == "7":
                statistic = "fouls"
            elif choice == "8":
                statistic = "offsides"
            elif choice == "9":
                statistic = "passes_attempted"
            elif choice == "10":
                statistic = "passes_completed"
            elif choice == "11":
                statistic = "corner_kicks"
            elif choice == "12":
                statistic = "goals_prevented"
            else:
                print("Invalid choice")

            max_value_teams(statistic, countries, eval(statistic))
            pass
        elif choice == "3":
            print("Which statistic would you like to use?")
            print("(1) Goals For")
            print("(2) Goals Against")
            print("(3) Yellow Cards")
            print("(4) Red Cards")
            print("(5) Possession Percentage")
            print("(6) Attempts")
            print("(7) Fouls")
            print("(8) Offsides")
            print("(9) Passes Attempted")
            print("(10) Passes Completed")
            print("(11) Corner Kicks")
            print("(12) Goals Prevented")

            choice = input("Enter a number to choose a statistic: ")
            if choice == "1":
                statistic = "goals_for"
            elif choice == "2":
                statistic = "goals_against"
            elif choice == "3":
                statistic = "yellow_cards"
            elif choice == "4":
                statistic = "red_cards"
            elif choice == "5":
                statistic = "possession_percent"
            elif choice == "6":
                statistic = "attempts"
            elif choice == "7":
                statistic = "fouls"
            elif choice == "8":
                statistic = "offsides"
            elif choice == "9":
                statistic = "passes_attempted"
            elif choice == "10":
                statistic = "passes_completed"
            elif choice == "11":
                statistic = "corner_kicks"
            elif choice == "12":
                statistic = "goals_prevented"
            else:
                print("Invalid choice")

            min_value_teams(statistic, countries, eval(statistic))
            pass
        elif choice == "4":
            print("Which statistic would you like to use?")
            print("(1) Goals For")
            print("(2) Goals Against")
            print("(3) Yellow Cards")
            print("(4) Red Cards")
            print("(5) Possession Percentage")
            print("(6) Attempts")
            print("(7) Fouls")
            print("(8) Offsides")
            print("(9) Passes Attempted")
            print("(10) Passes Completed")
            print("(11) Corner Kicks")
            print("(12) Goals Prevented")

            choice = input("Enter a number to choose a statistic: ")
            if choice == "1":
                statistic = "goals_for"
            elif choice == "2":
                statistic = "goals_against"
            elif choice == "3":
                statistic = "yellow_cards"
            elif choice == "4":
                statistic = "red_cards"
            elif choice == "5":
                statistic = "possession_percent"
            elif choice == "6":
                statistic = "attempts"
            elif choice == "7":
                statistic = "fouls"
            elif choice == "8":
                statistic = "offsides"
            elif choice == "9":
                statistic = "passes_attempted"
            elif choice == "10":
                statistic = "passes_completed"
            elif choice == "11":
                statistic = "corner_kicks"
            elif choice == "12":
                statistic = "goals_prevented"
            else:
                print("Invalid choice")

            above_average_teams(statistic, countries, eval(statistic))
            pass
        elif choice == "5":
            print("Which statistic would you like to use?")
            print("(1) Goals For")
            print("(2) Goals Against")
            print("(3) Yellow Cards")
            print("(4) Red Cards")
            print("(5) Possession Percentage")
            print("(6) Attempts")
            print("(7) Fouls")
            print("(8) Offsides")
            print("(9) Passes Attempted")
            print("(10) Passes Completed")
            print("(11) Corner Kicks")
            print("(12) Goals Prevented")

            choice = input("Enter a number to choose a statistic: ")
            if choice == "1":
                statistic = "goals_for"
            elif choice == "2":
                statistic = "goals_against"
            elif choice == "3":
                statistic = "yellow_cards"
            elif choice == "4":
                statistic = "red_cards"
            elif choice == "5":
                statistic = "possession_percent"
            elif choice == "6":
                statistic = "attempts"
            elif choice == "7":
                statistic = "fouls"
            elif choice == "8":
                statistic = "offsides"
            elif choice == "9":
                statistic = "passes_attempted"
            elif choice == "10":
                statistic = "passes_completed"
            elif choice == "11":
                statistic = "corner_kicks"
            elif choice == "12":
                statistic = "goals_prevented"
            else:
                print("Invalid choice")

            below_avg_teams(statistic, countries, eval(statistic))

            pass
        elif choice == "9":
            men = False;
            pass
        else:
            print("Invalid choice. Please try again.")
