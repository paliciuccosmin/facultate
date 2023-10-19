let search=document.querySelector('.search-box');

search=document.querySelector('#search-icon').onclick = ( ) =>{
    search.classList.toggle('active');
}
let header=document.querySelector('header');

window.addEventListener('scroll', () =>{
    header.classList.toggle('shadow', window.scrollY>e);
});