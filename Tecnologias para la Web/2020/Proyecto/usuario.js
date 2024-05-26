document.getElementById('user-menu-button').addEventListener('click', function() 
{
    var userMenu = document.getElementById('user-menu');
    userMenu.classList.toggle('hidden');
});

/*
// Optional: Close the dropdown when clicking outside of it
window.addEventListener('click', function(event) 
{
    var dropdownButton = document.getElementById('button-mobile-menu');
    var dropdownMenu = document.getElementById('mobile-menu');
    if (!dropdownButton.contains(event.target) && !dropdownMenu.contains(event.target)) 
    {
        dropdownMenu.classList.add('sm:hidden');
    }
});
*/