document.getElementById('mobile-menu-button').addEventListener('click', function() 
{
    var mobileMenu = document.getElementById('mobile-menu');
    mobileMenu.classList.toggle('hidden');
});

// Optional: Close the dropdown when clicking outside of it
window.addEventListener('click', function(event) 
{
    var mobileMenuButton = document.getElementById('mobile-menu-button');
    var mobileMenu = document.getElementById('mobile-menu');
    if (!mobileMenuButton.contains(event.target) && !mobileMenu.contains(event.target)) 
    {
        mobileMenu.classList.add('hidden');
    }
});

document.getElementById('user-menu-button').addEventListener('click', function() 
{
    var userMenu = document.getElementById('user-menu');
    userMenu.classList.toggle('hidden');
});