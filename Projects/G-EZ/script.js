// ===== Tab Switching =====
const tabs = document.querySelectorAll('.tab');
const tabContents = document.querySelectorAll('.tab-content');
const loadingBar = document.getElementById('loading-bar');

// Function to activate a tab
function activateTab(tabName) {
  // Remove active from all tabs and contents
  tabs.forEach(t => t.classList.remove('active'));
  tabContents.forEach(c => c.classList.remove('active'));

  // Add active to target
  const targetTab = document.querySelector(`.tab[data-tab="${tabName}"]`);
  const targetContent = document.getElementById(tabName);
  if(targetTab && targetContent) {
    targetTab.classList.add('active');
    targetContent.classList.add('active');
  }

  // Save active tab
  localStorage.setItem('lastTab', tabName);
}

// Load last active tab or default to first
const lastTab = localStorage.getItem('lastTab') || tabs[0].getAttribute('data-tab');
activateTab(lastTab);

// Add click events
tabs.forEach(tab => {
  tab.addEventListener('click', () => {
    const target = tab.getAttribute('data-tab');

    // Quick loading animation
    loadingBar.style.width = '50%';
    setTimeout(() => {
      loadingBar.style.width = '100%';
      setTimeout(() => {
        loadingBar.style.width = '0%';
      }, 150);
    }, 50);

    // Activate the clicked tab
    activateTab(target);
  });
});

// Super secret mode toggle
const themeToggle = document.getElementById('theme-toggle');

themeToggle.addEventListener('click', () => {
  document.body.classList.toggle('dark-mode');
  if(document.body.classList.contains('dark-mode')) {
    localStorage.setItem('theme', 'dark');
  } else {
    localStorage.setItem('theme', 'light');
  }
});

// Load theme preference
const savedTheme = localStorage.getItem('theme');
if(savedTheme === 'dark') {
  document.body.classList.add('dark-mode');
}
