const dataMusicTemplate = document.querySelector("[data-music-template]")
const dataMusicCardContainer = document.querySelector("[data-music-card-container]")
const searchInput = document.querySelector("[data-search]")
let musicData = []
searchInput.addEventListener("input", (e) => {
  const value = e.target.value.toLowerCase().replace(/\b(span|strong|italic|em)\b/g, 'asdfasdf').trim();
  //console.log(value)
  let IsVisible
  musicData.forEach(music=>{

    if (check[3].checked == true) {
      IsVisible = music.title.toLowerCase().includes(value) ||
        music.description.toString().toLowerCase().includes(value)
    }
    else if (check[0].checked == true) {
      IsVisible = music.title.toLowerCase().includes(value)
    }
    else if (check[1].checked == true) {
      IsVisible = music.description.toString().toLowerCase().includes(value)
    }
    else if (check[2].checked == true) {
      IsVisible = music.keywords.includes(value)
      //console.log(music.keywords)
      //console.log(IsVisible)
    }
    else if (check[0].checked == true&&check[1].checked == true) {
      IsVisible = music.title.toLowerCase().includes(value) ||
        music.description.toString().toLowerCase().includes(value)
    }
    else{
      IsVisible = music.title.toLowerCase().includes(value) ||
        music.description.toString().toLowerCase().includes(value)
    }
    music.element.classList.toggle("hide", !IsVisible)
  })
  let allElement = document.getElementsByClassName('description')
  for (var i = 0; i < allElement.length; i++) {
    onInput(value,allElement[i])
	}
  let allElement2 = document.getElementsByClassName('title')
  for (var i = 0; i < allElement2.length; i++) {
    onInput(value,allElement2[i])
	}
    
  
  
})

fetch('./data.json').then(response => {
  return response.json();
}).then(data => {
  console.log(data)

  musicData = data.sections[0].assets.map(assets => {

    const card = dataMusicTemplate.content.cloneNode(true).children[0]
    const header = card.querySelector("[data-header]")
    const headerTitle = card.querySelector("[data-header-title]")
    const body = card.querySelector("[data-body]")
    const duration = card.querySelector("[data-body-duration]")
    const description = card.querySelector("[data-body-description]")
    const PlayVocal = card.querySelector("[data-body-play-vocal]")
    const lyrics = card.querySelector("[data-body-lyrics]")
    headerTitle.textContent = assets.title
    //console.log(headerTitle)
    description.innerHTML = assets.description
    duration.textContent = assets.supplement_information
    PlayVocal.innerHTML = "&#9658; Play Vocal"
    lyrics.textContent = "Lyrics(PDF)"
    //console.log(description)
    //console.log(duration)
    //console.log(abc)
    dataMusicCardContainer.append(card)

    return { title: assets.title, description: assets.description, duration: assets.supplement_information, element: card, keywords:assets.keywords }
  })
  

}).catch(err => {
  // Do something for an error here
});

var check = document.querySelectorAll('input[name="checkbox"]')

function Clicked(checked){
  if (checked.id=='chk-All') {
    check[0].click()
    check[1].click()
    check[2].click()
  }
  if(check[0].checked==true&&check[1].checked==true&&check[2].checked==true){
    check[3].checked=true
  }
  else{
    check[3].checked=false
  }
  
//console.log(checked)
 }


var checkList = document.getElementById('list1');
//console.log(checkList)
checkList.getElementsByClassName('anchor')[0].onclick = function(evt) {
  if (checkList.classList.contains('visible'))
    checkList.classList.remove('visible');
  else
    checkList.classList.add('visible');
}

//find highlighter
function onInput(input,target) {
  //console.log(input)
  //console.log(target)
  highlight(input, target)
  
}

function highlight(input, target) {
  //console.log(target)
  const value = input.value
  const matches = findText(target.innerHTML, input)
  unwrap(target)
  matches.forEach(match => target.innerHTML = wrap(target.textContent, match[0], match[1]))
}

function findText(string, search) {
  const matches = []
  let i = -1
  let ind = 0
//console.log(string)
//console.log(search)
  do {
      i = string.indexOf(search, i + 1)
      if (i > -1) matches.push([i, i + search.length])
  }
  while (i > -1 && search)
//console.log(matches)
  
  return matches
}

function wrap(text, from, to) {
  if ((from !== 0 && from < 1) || !to) return text
  return `${text.slice(0, from)}<span class="highlight">${text.slice(from, to)}</span>${text.slice(to, text.length)}`
}

function unwrap(wrapper) {
  return Array.from(wrapper.querySelectorAll('.highlight')).forEach(target => target.replaceWith(target.textContent))
}