
# Fixture

When testing code that depends on models and the database, one can use fixtures as a way to generate temporary data tables loaded with sample data that can be used by the test.

CakePHP performs the following during the course of a fixture based test case:

1, Creates tables for each of the fixtures needed.
2, Populates tables with data, if data is provided in fixture.
3, Runs test methods.
4, Empties the fixture tables.
5, Removes fixture tables from database.


- Creating Fixtures

Things have to be considered

(1) How the table is created(Which fields are part of the table)
(2) Which recoreds will be initially populated to the table.

Make a fixture file in tests/Fixture directory

 
Defining the schema in fixture files can be really handy when creating plugins or libraries or if you are creating an application that needs to be portable between database vendors.
```
namespace App\Test\Fixture;

use Cake\TestSuite\Fixture\TestFixture;

class ArticlesFixture extends TestFixture
{

      // Optional. Set this property to load fixtures to a different test datasource
      public $connection = 'test';
      
      // This way is the best for me.
	  public $import = [
		'table' => '{table name}', // can get scheme from table
        'model' => '{model name}'  // can get scheme from model      
	  ];

      public $fields = [
		 (refer to documentation) 
      ];
	   
      // fake-data
      public $records = [
			(...)
      ];
 }
```

- Loading Fixtures in your Test Cases

```
// in Test class 

	public $fixtures = ['app.articles', 'app.comments'];
```

another way by controlling when the fixtures are loaded.

```
//in the test class 

    public $fixtures = ['app.articles', 'app.comments'];
    public $autoFixtures = false;

    public function testMyFunction()
    {
        $this->loadFixtures('Articles', 'Comments');
    }

```

