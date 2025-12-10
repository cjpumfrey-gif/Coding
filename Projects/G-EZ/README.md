# YOUR PROJECT TITLE
#### Video Demo:  <[URL HERE](https://www.youtube.com/watch?v=ZVc-GRejp8g)>
#### Description:

G-EZ is a one-page dashboard designed to simplify access to Google Workspace-like tools such as Gmail, Docs, Sheets, and Drive. The goal of this project is to provide a clean, interactive interface where users can quickly view emails, documents, spreadsheets, and files all in a single page, without having to navigate between multiple tabs or platforms. This project is built entirely with HTML, CSS, and JavaScript, with no external API dependencies, making it self-contained and easy to run in any modern browser. Intially I wanted to use google OAUTH to create a full working copy using googles available project API's however for the nature of this project that wasn't a wise choice, as that would of resulted in complications with uploading the code and requires registering for a cloud project with google.

### Motivation

During my exploration of web development, I wanted to create something practical but also visually engaging. I realized that many people, including students and professionals, often need to switch between Gmail, Google Docs, Sheets, and Drive, which can be time-consuming and disorganized. G-EZ is meant to simulate that experience in a simplified, lightweight dashboard. This project gave me the chance to practice JavaScript interactivity, CSS animations, and responsive design while building something useful.

### Key Features

- **Tab Navigation:** Users can switch between Gmail, Docs, Sheets, and Drive panels using clearly labeled tabs. Each transition is enhanced with a subtle fade animation and loading bar to make the experience smooth and visually pleasing.
- **Gmail Panel:** Displays a list of sample emails. Hover animations improve readability and interactivity.
- **Docs Panel:** Shows recent documents as clickable cards that highlight on hover. This panel demonstrates the use of CSS grid layout and card design patterns.
- **Sheets Panel:** Spreadsheets are displayed in a simple table format with hover effects for better readability.
- **Drive Panel:** Files and folders are shown in a grid layout with subtle animations, giving a sense of depth and interactivity.
- **Dark Mode Toggle:** A convenient toggle button allows users to switch between light and dark themes. The theme preference is stored in `localStorage`, so the user’s choice persists across sessions.
- **Quick Loading Animation:** Each tab switch is accompanied by a brief loading bar animation, enhancing user experience without adding delays or slowing the user experience.

### Design Choices

I prioritized simplicity, usability, and responsiveness. All features are contained within a single page to minimize complexity. The dark mode implementation ensures readability and visual comfort, and animations were designed to be subtle so that the interface feels smooth but not distracting. Using `localStorage` for theme persistence allowed me to explore browser storage APIs while keeping the project lightweight.

### Implementation Details

- **HTML (`index.html`)**: Contains semantic structure for header, navigation, main content, and footer. Each tab panel has unique IDs to allow JavaScript to control visibility.
- **CSS (`style.css`)**: Handles layout, colors, typography, responsive design, hover effects, dark mode styling, and transition animations.
- **JavaScript (`script.js`)**: Manages tab switching, dark mode toggling, and loading animation. Event listeners ensure smooth interactions, while functions handle saving and loading user preferences.

### Challenges & Learning Outcomes

One challenge was creating smooth tab transitions without external libraries. By combining CSS transitions with JavaScript DOM manipulation, I achieved a fluid experience. Another challenge was ensuring dark mode applied consistently to all elements, including the footer, which required carefully managing CSS classes. From this project, I gained confidence in structuring HTML for interactive pages, managing state in JavaScript, and designing with user experience in mind.

### Future Enhancements

Given more time, I could:

- Integrate real Google Workspace APIs to fetch actual emails, documents, and files.
- Alternatively I could look into using my networking experience to create and host a file server and mail server and creating my own proprietary suite.
- Add search functionality within each panel for better usability.
- Enhance animations further with subtle micro-interactions for a more polished feel.
- Implement drag-and-drop for Drive files and folders.

### Files Included

- `index.html`: Main HTML file with structured layout and semantic elements.
- `style.css`: Contains all styling, transitions, dark mode, and animations.
- `script.js`: Handles tab navigation, dark mode toggle, and loading bar logic.
- `README.md`: Documentation of the project, features, and implementation details.


your project’s title; G-EZ Google Dashboard
your name; Conor Pumfrey
your GitHub and edX usernames; cjpumfrey-gif
your city and country; Kincardine, Ontario, Canada
and, the date you have recorded this video; November 5th 2025
