const express = require('express');
const bodyParser = require('body-parser');

const app = express();
const port = 3000;

app.use(bodyParser.json());

const recipes = [
  {
    name: "Pasta Carbonara",
    ingredients: ["Spaghetti", "Eggs", "Bacon", "Parmesan cheese", "Black pepper"],
    instructions: "Cook the spaghetti. Meanwhile, fry the bacon. Mix eggs, cheese, and pepper. Combine all ingredients and serve."
  },
  {
    name: "Chicken Stir-Fry",
    ingredients: ["Chicken breast", "Broccoli", "Bell peppers", "Soy sauce", "Garlic", "Ginger"],
    instructions: "Slice chicken and stir-fry until cooked. Add vegetables, soy sauce, garlic, and ginger. Cook until vegetables are tender."
  }
];

// Get all recipes
app.get('/recipes', (req, res) => {
  res.json(recipes);
});

// Add a new recipe
app.post('/recipes', (req, res) => {
  const newRecipe = req.body;
  if (!newRecipe.name || !newRecipe.ingredients || !newRecipe.instructions) {
    return res.status(400).json({ error: 'Missing fields: name, ingredients, or instructions' });
  }
  recipes.push(newRecipe);
  res.json({ message: 'Recipe added successfully', recipe: newRecipe });
});

// Search for a specific recipe
app.get('/recipes/:name', (req, res) => {
  const recipeName = req.params.name.toLowerCase();
  const recipe = recipes.find(r => r.name.toLowerCase() === recipeName);
  if (recipe) {
    res.json(recipe);
  } else {
    res.status(404).json({ error: 'Recipe not found' });
  }
});

// Fix template literal error
app.listen(port, () => {
  console.log(`Server is running at http://localhost:${port}`);
});


//not working
