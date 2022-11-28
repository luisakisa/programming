package DB;

public class FactoryDB{
    public IDB getDB(DBTypes type){
        IDB db = null;
        switch (type) {
            case PostgreDB:
                db = new PostgreDB();
                break;
            // case SQL:
            //     toReturn = new SQLDB();
            //     break;
            // case MongoDB:
            //     toReturn = new MongoDB();
                // break;
            default:
                throw new IllegalArgumentException("Wrong doughnut type:" + type);
        }
        return db;
    }
}