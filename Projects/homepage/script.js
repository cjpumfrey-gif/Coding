document.addEventListener("DOMContentLoaded", function() {

  // Greeting button (on index)
  const greetBtn = document.querySelector("#greetBtn");
  if (greetBtn) {
    greetBtn.addEventListener("click", () => {
      alert("Hello there! 👋 Thanks for visiting my homepage!");
    });
  }

  // Contact form alert
  const form = document.querySelector("#contactForm");
  if (form) {
    form.addEventListener("submit", function(event) {
      event.preventDefault();
      const name = document.querySelector("#name").value;
      alert(`Thanks, ${name}! Your message has been sent.`);
      form.reset();
    });
  }
});
