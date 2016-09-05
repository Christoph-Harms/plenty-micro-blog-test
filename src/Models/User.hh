<?hh //strict

namespace Plitter\Models;

use Plitter\Data\FireBaseModel;


/**
*
* @property string $name
* @property string $birthday
*/
class User extends FireBaseModel
{
  public static string $dataName = 'users';

  private static function validate(array<string, mixed> $data):bool
  {

    return false;
  }
}
