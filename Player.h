class Player {
    public:

    int getLevel() const;
    void levelUp();
    void addCoins(int loot);
    void damage(int hpLoss);
    bool pay(int cost);
    void heal(int hpAddition);
    int getAttackStrength() const;
};