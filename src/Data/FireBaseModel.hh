<?hh //strict

namespace Plitter\Data;

use Plitter\Models\User;

abstract class FireBaseModel
{
  const string FIREBASE_BASE = 'https://plitter-2b674.firebaseio.com/';

  protected static string $dataName = '';

  public static function all():array<string, mixed>
  {
    $reqString = static::FIREBASE_BASE . static::$dataName . '.json';
    $ch = curl_init($reqString);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);

    $response = json_decode(curl_exec($ch), true);

    curl_close($ch);

    return $response;
  }

  public static function store(array<string, mixed> $data):string
  {
    $data = json_encode($data);
    $reqString = static::FIREBASE_BASE . static::$dataName . '.json';
    $ch = curl_init($reqString);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($ch, CURLOPT_POST, true);
    curl_setopt($ch, CURLOPT_POSTFIELDS, $data);
    curl_setopt($ch, CURLOPT_HTTPHEADER, array(
      'Content-Type: application/json',
      'Content-Length: ' . strlen($data))
    );

    $res = curl_exec($ch);

    return $res;
  }

}
