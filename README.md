# Study Game📚

The **Study Game** is an application designed to turn everyday tasks into a motivational and rewarding experience. At its core, the game features two primary tables: one for activities and another for items. The activities table represents a wide range of real-world actions that the user can perform, such as studying, exercising, or completing daily chores. Each activity is linked to the possibility of earning rewards, and once the user reports the completion of an activity to the program, they are granted one or more of three valuable resources: coins, diamonds, or rubies.

These resources serve as the in-game currency, which the user can accumulate over time. The items table offers a variety of rewards that can be purchased with these resources. Unlike typical in-game rewards, the items in Study Game are tangible and can be enjoyed in the real world. The program acts as a mediator, translating the user's real-world achievements into meaningful rewards, thereby creating a direct connection between personal productivity and real-life benefits.

Study Game is designed to make daily routines more engaging and fulfilling by providing a unique and interactive way to stay motivated. Whether you are aiming to improve your personal habits, stay on track with your studies, or maintain a healthy lifestyle, this application offers a structured yet enjoyable way to achieve your goals. By bridging the gap between virtual rewards and real-world benefits, Study Game helps users stay disciplined and focused, turning the pursuit of personal and professional growth into a game that yields tangible, lasting results.

## Key Technical Concepts in the Study Game Code

1. **Class Structure and Inheritance👪**:
   The code uses C++ classes to encapsulate the behavior of different entities within the game. The `Unit` class serves as a base class, holding common attributes like `id`, `title`, and `Value` (a struct that holds the resources: `coins`, `diamonds`, and `rubies`). The `Earning` and `Spending` classes inherit from `Unit`, extending it with methods that modify the user's resources. Inheritance is utilized here to enforce a consistent interface and reuse code efficiently across different game elements.

2. **Resource Management💎**:
   The core of the game involves managing in-game resources (coins, diamonds, rubies) based on the user's activities. The `Earning` class's `increaseValues()` method increases the user's resources when an activity is completed, while the `Spending` class's `decreaseValues()` method decreases them when an item is purchased. These methods rely on converting string representations of the resources to integers, performing arithmetic, and then converting them back to strings. This design ensures that resources are consistently updated and provides feedback to the user about their current status.

3. **Persistent Storage with Text Files📄**:
   The game uses a text file (`userdata.txt`) to store and retrieve the user's progress, including their username and current resource counts. The `checkTxtFile()`, `createTxtFile()`, `readTxtFile()`, and `reWriteTxtFile()` functions handle the file I/O operations. By saving the game state to a text file, the program ensures that progress is not lost between sessions, providing a persistent user experience. The use of text files here is a simple yet effective way to manage user data without the need for complex databases.
